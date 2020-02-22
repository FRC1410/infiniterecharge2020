#include "Commands/Looped/Drive.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

Drive::Drive() {
  Requires(&Robot::m_drivetrain);
}

void Drive::Initialize() {
  invert_driving_was_pressed = Robot::m_oi.GetDriverButton(kInvertDrivingButton);
  first_timer = true;
  m_timer.Reset();
  m_timer.Start();
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
}

bool Drive::IsFinished() {
  return false;
}

void Drive::End() {}

void Drive::Interrupted() {}