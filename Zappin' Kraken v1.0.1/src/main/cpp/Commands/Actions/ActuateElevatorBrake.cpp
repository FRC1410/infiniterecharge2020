#include "Commands/Actions/ActuateElevatorBrake.h"
#include "Robot.h"

ActuateElevatorBrake::ActuateElevatorBrake() {
  has_desired_position = false;
}

ActuateElevatorBrake::ActuateElevatorBrake(bool position) {
  has_desired_position = true;
  desired_position = position;
}

void ActuateElevatorBrake::Initialize() {
  if (has_desired_position == true) {
    Robot::m_elevator.SetBrake(desired_position);
  } else {
    Robot::m_elevator.SetBrake(!Robot::m_elevator.GetBrake());
  }
}

void ActuateElevatorBrake::Execute() {}

bool ActuateElevatorBrake::IsFinished() {
  return true;
}

void ActuateElevatorBrake::End() {}

void ActuateElevatorBrake::Interrupted() {}