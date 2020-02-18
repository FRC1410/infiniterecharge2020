#include "Commands/Looped/Drive.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

Drive::Drive() {
  Requires(&Robot::m_drivetrain);
}

void Drive::Initialize() {
  invert_driving_was_pressed = false;
  first_timer = true;
  m_timer.Reset();
  m_timer.Start();

  Robot::m_drivetrain.ResetEncoders();

  x_position = 0;
  z_position = 0;
  prev_distance = 0;
}

void Drive::Execute() {
  if (Robot::m_oi.GetDriverButton(kInvertDrivingButton) == true) {
    if (invert_driving_was_pressed == false) {
      first_timer = false;
      m_timer.Reset();
      invert_driving *= -1;
    }
    invert_driving_was_pressed = true;
  } else {
    invert_driving_was_pressed = false;
  }

  left_input = Robot::m_oi.GetDriverAxis(kLeftDriveAxis);
  right_input = Robot::m_oi.GetDriverAxis(kRightDriveAxis);
  Robot::m_drivetrain.SetCurvedArcadeSpeed(invert_driving * ((left_input + right_input) / 2), (left_input - right_input) / 2);

  if (m_timer.Get() < kSingleRumbleTime && first_timer == false) {
    Robot::m_oi.SetDriverRumble(kSingleRumbleStrength);
  } else {
    Robot::m_oi.SetDriverRumble(0);
  }

  frc::SmartDashboard::PutNumber("Shooter RPM", Robot::m_shooter.GetRPM());
  

  linear_displacement = 2 * (Robot::m_drivetrain.GetDistance() - prev_distance) * abs(sin((Robot::m_drivetrain.GetAngle()) * pi/180.0) / ((Robot::m_drivetrain.GetAngle()) * pi/180.0));
  x_position += sin(Robot::m_drivetrain.GetAngle() * pi/180.0) * linear_displacement;
  z_position += cos(Robot::m_drivetrain.GetAngle() * pi/180.0) * linear_displacement;

  //Robot::m_drivetrain.IncrementXZ();

  frc::SmartDashboard::PutNumber("New Zed", z_position);
  frc::SmartDashboard::PutNumber("DT", m_timer.Get() - previous_timer);
  frc::SmartDashboard::PutNumber("New DX", Robot::m_drivetrain.GetAngle() - prev_distance);
  frc::SmartDashboard::PutNumber("Old Distance", prev_distance);
  prev_distance = Robot::m_drivetrain.GetAngle();
  frc::SmartDashboard::PutNumber("New Distance", prev_distance);
  previous_timer = m_timer.Get();
}

bool Drive::IsFinished() {
  return false;
}

void Drive::End() {}

void Drive::Interrupted() {}