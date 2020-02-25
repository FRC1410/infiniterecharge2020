#include "Auto/Actions/DriveToPoint.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

DriveToPoint::DriveToPoint(double x_target_input, double z_target_input, double angle_target_input) {
  Requires(&Robot::m_drivetrain);
  x_target = x_target_input;
  z_target = z_target_input;
  angle_target = fmod(fmod(angle_target_input - Robot::m_drivetrain.GetAngle() + 180, 360) + 360, 360) - 180 + Robot::m_drivetrain.GetAngle();
  ending_speed = 0;
  acceleration_time = -1;
}

DriveToPoint::DriveToPoint(double x_target_input, double z_target_input, double angle_target_input, double ending_speed_input) {
  Requires(&Robot::m_drivetrain);
  x_target = x_target_input;
  z_target = z_target_input;
  angle_target = fmod(fmod(angle_target_input - Robot::m_drivetrain.GetAngle() + 180, 360) + 360, 360) - 180 + Robot::m_drivetrain.GetAngle();
  ending_speed = ending_speed_input;
  acceleration_time = -1;
}

DriveToPoint::DriveToPoint(double x_target_input, double z_target_input, double angle_target_input, double ending_speed_input, double acceleration_time_input) {
  Requires(&Robot::m_drivetrain);
  x_target = x_target_input;
  z_target = z_target_input;
  angle_target = fmod(fmod(angle_target_input - Robot::m_drivetrain.GetAngle() + 180, 360) + 360, 360) - 180 + Robot::m_drivetrain.GetAngle();
  ending_speed = ending_speed_input;
  acceleration_time = acceleration_time_input;
}

void DriveToPoint::CalculatePosition() { 
  x_difference = Robot::m_drivetrain.GetX() - x_target;
  z_difference = Robot::m_drivetrain.GetZ() - z_target;
  translated_x = x_difference * cos(angle_target * pi/180) - z_difference * sin(angle_target * pi/180);
  translated_z = x_difference * sin(angle_target * pi/180) + z_difference * cos(angle_target * pi/180);
}

void DriveToPoint::Initialize() {
  CalculatePosition();
  starting_speed = Robot::m_drivetrain.GetLinearCurvedSpeed();
  starting_translated_z = translated_z;

  m_angle_PID.SetConstants(drivetrain_angle_kP, drivetrain_angle_kI, drivetrain_angle_kD);
  m_angle_PID.ResetI();
  m_angle_PID.ResetD();

  m_offset_PID.SetConstants(x_offset_kP, x_offset_kI, x_offset_kD);
  m_offset_PID.ResetI();
  m_offset_PID.ResetD();

  if (ending_speed == 0) {
    m_distance_PID.SetConstants(drivetrain_distance_kP, drivetrain_distance_kI, drivetrain_distance_kD);
    m_distance_PID.ResetI();
    m_distance_PID.ResetD();
  }

  previous_time = 0;
  m_timer.Reset();
  m_timer.Start();
}

void DriveToPoint::Execute() {
  CalculatePosition();
  if (ending_speed == 0) {
    linear_speed = m_distance_PID.GetPID(translated_z, 0, m_timer.Get() - previous_time);
  } else if (acceleration_time >= 0) {
    linear_speed = starting_speed + ((ending_speed - starting_speed) * (std::min(m_timer.Get(), acceleration_time) / acceleration_time));
  } else {
    linear_speed = ending_speed - ((ending_speed - starting_speed) * (std::min(abs(translated_z), abs(starting_translated_z)) / abs(starting_translated_z)));
  }

  PID_angle_target = atan(m_offset_PID.GetPID(-translated_x * abs(translated_z) / translated_z, 0, m_timer.Get() - previous_time)) * 180/pi;
  rotational_speed = m_angle_PID.GetPID(Robot::m_drivetrain.GetAngle(), angle_target + PID_angle_target, m_timer.Get() - previous_time);
  Robot::m_drivetrain.CurvedArcadeAccelerate(linear_speed, rotational_speed, m_timer.Get() - previous_time);

  previous_time = m_timer.Get();
}

bool DriveToPoint::IsFinished() {
  if (ending_speed == 0) {
    return (abs(translated_z) < kDistanceFinishedThreshold);
  } else {
    return ((translated_z * starting_translated_z) < 0);
  }
}

void DriveToPoint::End() {
  Robot::m_drivetrain.SetCurvedArcadeSpeed(ending_speed, 0);
}

void DriveToPoint::Interrupted() {
  End();
}