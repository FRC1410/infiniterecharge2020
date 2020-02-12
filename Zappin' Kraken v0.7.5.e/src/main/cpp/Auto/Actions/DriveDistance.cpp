#include "Auto/Actions/DriveDistance.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

DriveDistance::DriveDistance(double distance_input) {
  Requires(&Robot::m_drivetrain);
  distance_target = distance_input;
  ending_speed = 0;
  acceleration_time = -1;
}

DriveDistance::DriveDistance(double distance_input, double ending_speed_input) {
  Requires(&Robot::m_drivetrain);
  distance_target = distance_input;
  ending_speed = ending_speed_input;
  acceleration_time = -1;
}

DriveDistance::DriveDistance(double distance_input, double ending_speed_input, double acceleration_time_input) {
  Requires(&Robot::m_drivetrain);
  distance_target = distance_input;
  ending_speed = ending_speed_input;
  acceleration_time = acceleration_time_input;
}

void DriveDistance::Initialize() {
  starting_distance = Robot::m_drivetrain.GetDistance();
  distance_target += Robot::m_drivetrain.GetDistance();
  starting_speed = Robot::m_drivetrain.GetLinearCurvedSpeed();

  if (ending_speed == 0) {
    m_PID.SetConstants(drivetrain_distance_kP, drivetrain_distance_kI, drivetrain_distance_kD);
    m_PID.ResetI();
    m_PID.ResetD();
  }

  previous_time = 0;
  m_timer.Reset();
  m_timer.Start();
}

void DriveDistance::Execute() {
  if (ending_speed == 0) {
    speed = m_PID.GetPID(Robot::m_drivetrain.GetDistance(), distance_target, m_timer.Get() - previous_time);
  } else if (acceleration_time >= 0) {
    speed = starting_speed + ((ending_speed - starting_speed) * (std::min(m_timer.Get(), acceleration_time) / acceleration_time));
  } else {
    speed = starting_speed + ((ending_speed - starting_speed) * ((Robot::m_drivetrain.GetDistance() - starting_distance) / (distance_target - starting_distance)));
  }
}

bool DriveDistance::IsFinished() {
  return (abs(distance_target - Robot::m_drivetrain.GetDistance()) < kDistanceFinishedThreshold);
}

void DriveDistance::End() {}

void DriveDistance::Interrupted() {}