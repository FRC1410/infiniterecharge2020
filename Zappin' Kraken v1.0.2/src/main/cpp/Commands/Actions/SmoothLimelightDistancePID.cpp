#include "Commands/Actions/SmoothLimelightDistancePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"
#include "RobotMap/Constants.h"

SmoothLimelightDistancePID::SmoothLimelightDistancePID() {
  Requires(&Robot::m_drivetrain);
}

void SmoothLimelightDistancePID::Initialize() {
  m_angle_PID.SetConstants(limelight_angle_kP, limelight_angle_kI, limelight_angle_kD);
  m_angle_PID.ResetI();
  m_angle_PID.ResetD();
  
  m_distance_PID.SetConstants(limelight_distance_kP, limelight_distance_kI, limelight_distance_kD);
  m_distance_PID.ResetI();
  m_distance_PID.ResetD();

  for (int x = 0; x < (sizeof(distance_history) / kDoubleSize); x++) {
    distance_history[x] = 0;
  }

  target_distance = Robot::m_limelight.GetNearestDistanceTarget();

  m_finished_timer.Reset();
  m_finished_timer.Stop();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void SmoothLimelightDistancePID::Execute() {
  if (Robot::m_limelight.GetTarget() == true) {
    for (int x = (sizeof(distance_history) / kDoubleSize); x > 0; x--) {
      distance_history[x] = distance_history[x - 1];
    }
    distance_history[0] = Robot::m_limelight.GetDistance();

    distance_sum = 0;
    uninitialized = 0;

    for (int x = 0; x < (sizeof(distance_history) / kDoubleSize); x++) {
      if (distance_history[x] != 0) {
        distance_sum += distance_history[x];
      } else {
        uninitialized++;
      }
    }
    average_distance = distance_sum / ((sizeof(distance_history) / kDoubleSize) - uninitialized);

    linear_speed = -m_distance_PID.GetPID(average_distance, target_distance, m_timer.Get() - previous_timer);
    rotational_speed = -m_angle_PID.GetPID(Robot::m_limelight.GetXAngle(), -Robot::m_limelight.GetNearestAngleOffset(), m_timer.Get() - previous_timer);

    if (abs(linear_speed) > kLimelightLinearCap) {
      linear_speed = kLimelightLinearCap * (abs(linear_speed) / linear_speed);
    }
    Robot::m_drivetrain.SetCurvedArcadeSpeed(linear_speed, rotational_speed);

    if ((abs(average_distance - target_distance) < kLimelightDistanceFinishedThreshold)) {
      m_finished_timer.Start();
    } else {
      m_finished_timer.Reset();
      m_finished_timer.Stop();
    }
  } else {
    Robot::m_drivetrain.SetRawSpeed(0, 0);
  }
  previous_timer = m_timer.Get();
}

bool SmoothLimelightDistancePID::IsFinished() {
  return (m_finished_timer.Get() > kLimelightDistanceFinishedTimeThreshold);
}

void SmoothLimelightDistancePID::End() {
  Robot::m_limelight.SetLastProfile();
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void SmoothLimelightDistancePID::Interrupted() {
  End();
}