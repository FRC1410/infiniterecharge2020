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
  /*kP = frc::SmartDashboard::GetNumber("Limelight Angle kP", limelight_sqrt_angle_kP);
  kI = frc::SmartDashboard::GetNumber("Limelight Angle kI", limelight_sqrt_angle_kI);
  kD = frc::SmartDashboard::GetNumber("Limelight Angle kD", limelight_sqrt_angle_kD);*/
  //m_PID.SetConstants(limelight_sqrt_angle_kP, limelight_sqrt_angle_kI, limelight_sqrt_angle_kD);
  //m_PID.SetConstants(kP, kI, kD);
  Robot::m_drivetrain.SetCurvedArcadeSpeed(0, -m_PID.GetPID((Robot::m_limelight.GetXAngle() + kLimelightAngleOffset) / sqrt(abs(Robot::m_limelight.GetXAngle() + kLimelightAngleOffset)), 0, m_timer.Get() - previous_timer));
  previous_timer = m_timer.Get();
  frc::SmartDashboard::PutNumber("Angle Error", Robot::m_limelight.GetXAngle() + kLimelightAngleOffset);
}

bool LimelightAnglePID::IsFinished() {
  return (abs(Robot::m_limelight.GetXAngle() + kLimelightAngleOffset) < kLimelightAngleFinishedThreshold);
}

void LimelightAnglePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
  //Robot::m_limelight.ForceLightsOff();
}

void LimelightAnglePID::Interrupted() {
  End();
}