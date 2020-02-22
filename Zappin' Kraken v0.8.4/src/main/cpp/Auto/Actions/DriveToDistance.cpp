#include "Auto/Actions/DriveToDistance.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

DriveToDistance::DriveToDistance(double distance_input) {
  Requires(&Robot::m_drivetrain);
  distance_target1 = distance_input;
  ending_speed = 0;
  acceleration_time = -1;
}

DriveToDistance::DriveToDistance(double distance_input, double ending_speed_input) {
  Requires(&Robot::m_drivetrain);
  distance_target1 = distance_input;
  ending_speed = ending_speed_input;
  acceleration_time = -1;
}

DriveToDistance::DriveToDistance(double distance_input, double ending_speed_input, double acceleration_time_input) {
  Requires(&Robot::m_drivetrain);
  distance_target1 = distance_input;
  ending_speed = ending_speed_input;
  acceleration_time = acceleration_time_input;
}

void DriveToDistance::Initialize() {
  starting_distance = Robot::m_drivetrain.GetDistance();
  distance_target = starting_distance + distance_target1;
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

void DriveToDistance::Execute() {
  frc::SmartDashboard::PutNumber("Distance Target", distance_target);
  frc::SmartDashboard::PutNumber("Starting Distance line", starting_distance);
  frc::SmartDashboard::PutNumber("Drive off line error", distance_target - Robot::m_drivetrain.GetDistance());
  if (ending_speed == 0) {
    speed = m_PID.GetPID(Robot::m_drivetrain.GetDistance(), distance_target, m_timer.Get() - previous_time);
  } else if (acceleration_time >= 0) {
    speed = starting_speed + ((ending_speed - starting_speed) * (std::min(m_timer.Get(), acceleration_time) / acceleration_time));
  } else {
    speed = starting_speed + ((ending_speed - starting_speed) * ((Robot::m_drivetrain.GetDistance() - starting_distance) / (distance_target - starting_distance)));
  }
  Robot::m_drivetrain.CurvedArcadeAccelerate(speed, 0, m_timer.Get() - previous_time);
}

bool DriveToDistance::IsFinished() {
  return (abs(distance_target - Robot::m_drivetrain.GetDistance()) < kDistanceFinishedThreshold);
}

void DriveToDistance::End() {
  Robot::m_drivetrain.SetCurvedArcadeSpeed(ending_speed, 0);
}

void DriveToDistance::Interrupted() {
  End();
}