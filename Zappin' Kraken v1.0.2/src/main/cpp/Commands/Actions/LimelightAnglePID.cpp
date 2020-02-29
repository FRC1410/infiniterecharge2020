#include "Commands/Actions/LimelightAnglePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

LimelightAnglePID::LimelightAnglePID() {
  Requires(&Robot::m_drivetrain);
}

void LimelightAnglePID::Initialize() {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  angle_error_entry = table->GetEntry("Angle Error");

  m_PID.SetConstants(limelight_sqrt_angle_kP, limelight_sqrt_angle_kI, limelight_sqrt_angle_kD);
  m_PID.ResetI();
  m_PID.ResetD();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void LimelightAnglePID::Execute() {
  if (Robot::m_limelight.GetTarget() == true) {
    error = Robot::m_limelight.GetXAngle() + Robot::m_limelight.GetNearestAngleOffset();
    Robot::m_drivetrain.SetCurvedArcadeSpeed(0, -m_PID.GetPID(error / sqrt(abs(error)), 0, m_timer.Get() - previous_timer));
  } else {
    Robot::m_drivetrain.SetRawSpeed(0, 0);
  }
  previous_timer = m_timer.Get();
}

bool LimelightAnglePID::IsFinished() {
  return (abs(Robot::m_limelight.GetXAngle() + Robot::m_limelight.GetNearestAngleOffset()) < kLimelightAngleFinishedThreshold);
}

void LimelightAnglePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void LimelightAnglePID::Interrupted() {
  End();
}