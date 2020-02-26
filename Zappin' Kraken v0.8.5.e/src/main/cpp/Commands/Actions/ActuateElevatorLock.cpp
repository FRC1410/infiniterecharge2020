#include "Commands/Actions/ActuateElevatorLock.h"
#include "Robot.h"

ActuateElevatorLock::ActuateElevatorLock() {
  has_desired_position = false;
}

ActuateElevatorLock::ActuateElevatorLock(bool position) {
  has_desired_position = true;
  desired_position = position;
}

void ActuateElevatorLock::Initialize() {
  if (has_desired_position == true) {
    Robot::m_elevator.SetLock(desired_position);
  } else {
    Robot::m_elevator.SetLock(!Robot::m_elevator.GetLock());
  }
}

void ActuateElevatorLock::Execute() {}

bool ActuateElevatorLock::IsFinished() {
  return true;
}

void ActuateElevatorLock::End() {}

void ActuateElevatorLock::Interrupted() {}