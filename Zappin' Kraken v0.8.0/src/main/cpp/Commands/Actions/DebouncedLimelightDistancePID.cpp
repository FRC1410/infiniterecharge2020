#include "Commands/Actions/DebouncedLimelightDistancePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"
#include "RobotMap/Constants.h"

DebouncedLimelightDistancePID::DebouncedLimelightDistancePID() {
  Requires(&Robot::m_drivetrain);
}

void DebouncedLimelightDistancePID::Initialize() {
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

  for (int j = 0; j < (sizeof(distHist)/kDoubleSize); j++) {
    distHist[j] = 0;
  }

  m_finished_timer.Reset();
  m_finished_timer.Stop();
}

void DebouncedLimelightDistancePID::Execute() {
  kP = frc::SmartDashboard::GetNumber("Debounced kP", limelight_distance_kP);
  kI = frc::SmartDashboard::GetNumber("Debounced kI", limelight_distance_kI);
  kD = frc::SmartDashboard::GetNumber("Debounced kD", limelight_distance_kD);
  
  m_distance_PID.SetConstants(kP, kI, kD);

  int distSum = 0;
  int distUninitialized = 0;
  for (int i = (sizeof(distHist)/kDoubleSize); i > 0; i--) {
    distHist[i] = distHist[i - 1];
  }
  distHist[0] = Robot::m_limelight.GetDistance();

  for (int j = 0; j < (sizeof(distHist)/kDoubleSize); j++) {
    if (distHist[j] != 0) {
      distSum += distHist[j];
    } else {
      distUninitialized++;
    }
  }
  avDist = distSum/((sizeof(distHist)/kDoubleSize) - distUninitialized);

  frc::SmartDashboard::PutNumber("avDist", avDist);
  
  linear_speed = -m_distance_PID.GetPID(avDist, target_distance, m_timer.Get() - previous_timer);
  rotational_speed = -m_angle_PID.GetPID(Robot::m_limelight.GetXAngle(), -kLimelightAngleOffset, m_timer.Get() - previous_timer);

  if (abs(linear_speed) > kLimelightLinearCap) {
    linear_speed = kLimelightLinearCap * (abs(linear_speed) / linear_speed);
  }

  Robot::m_drivetrain.SetCurvedArcadeSpeed(linear_speed, rotational_speed);
  previous_timer = m_timer.Get();

  if ((abs(avDist - target_distance) < kDistanceFinishedThreshold)) {
    m_finished_timer.Start();
  } else {
    m_finished_timer.Reset();
    m_finished_timer.Stop();
  }
}

bool DebouncedLimelightDistancePID::IsFinished() {
  return (m_finished_timer.Get() > 0.5);
}

void DebouncedLimelightDistancePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void DebouncedLimelightDistancePID::Interrupted() {
  End();
}