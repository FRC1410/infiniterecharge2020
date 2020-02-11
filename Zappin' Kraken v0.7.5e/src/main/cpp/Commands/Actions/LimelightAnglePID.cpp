#include "Commands/Actions/LimelightAnglePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

LimelightAnglePID::LimelightAnglePID() {
  Requires(&Robot::m_drivetrain);
}

void LimelightAnglePID::Initialize() {
  m_PID.SetConstants(limelight_angle_kP, limelight_angle_kI, limelight_angle_kD);
  m_PID.ResetI();
  m_PID.ResetD();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void LimelightAnglePID::Execute() {
  Robot::m_drivetrain.SetCurvedArcadeSpeed(0, -m_PID.GetPID(Robot::m_limelight.GetXAngle(), -kLimelightAngleOffset, m_timer.Get() - previous_timer));
  previous_timer = m_timer.Get();
  frc::SmartDashboard::PutNumber("Angle Error", Robot::m_limelight.GetXAngle() + kLimelightAngleOffset);
}

bool LimelightAnglePID::IsFinished() {
  return (abs(Robot::m_limelight.GetXAngle() + kLimelightAngleOffset) < kLimelightAngleFinishedThreshold);
}

void LimelightAnglePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void LimelightAnglePID::Interrupted() {
  End();
}