#include "Commands/Actions/LimelightDistancePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

LimelightDistancePID::LimelightDistancePID() {
  Requires(&Robot::m_drivetrain);
}

void LimelightDistancePID::Initialize() {
  m_angle_PID.SetConstants(limelight_angle_kP, limelight_angle_kI, limelight_angle_kD);
  m_angle_PID.ResetI();
  m_angle_PID.ResetD();
  
  m_distance_PID.SetConstants(limelight_distance_kP, limelight_distance_kI, limelight_distance_kD);
  m_distance_PID.ResetI();
  m_distance_PID.ResetD();

  target_distance = Robot::m_limelight.GetNearestDistanceTarget();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void LimelightDistancePID::Execute() {
  linear_speed = -m_distance_PID.GetPID(Robot::m_limelight.GetDistance(), target_distance, m_timer.Get() - previous_timer);
  rotational_speed = -m_angle_PID.GetPID(Robot::m_limelight.GetXAngle(), -kLimelightAngleOffset, m_timer.Get() - previous_timer);
  
frc::SmartDashboard::PutNumber("Desired Linear Speed", linear_speed);

  if (abs(linear_speed) > kLimelightLinearCap) {
    linear_speed = kLimelightLinearCap * (abs(linear_speed) / linear_speed);
  }

  Robot::m_drivetrain.SetCurvedArcadeSpeed(linear_speed, rotational_speed);
  previous_timer = m_timer.Get();
  
}

bool LimelightDistancePID::IsFinished() {
  return (abs(Robot::m_limelight.GetDistance() - target_distance) < kDistanceFinishedThreshold);
}

void LimelightDistancePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void LimelightDistancePID::Interrupted() {
  End();
}