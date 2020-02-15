#include "Commands/Actions/ActuateElevatorLock.h"
#include "Robot.h"

ActuateElevatorLock::ActuateElevatorLock() {
  Requires(&Robot::m_elevator);
}

void ActuateElevatorLock::Initialize() {
  if (Robot::m_elevator.GetElevatorLock() == false) {
    Robot::m_elevator.LockElevator();
  } else {
    Robot::m_elevator.UnlockElevator();
  }
}

void ActuateElevatorLock::Execute() {}

bool ActuateElevatorLock::IsFinished() {
  return true;
}

void ActuateElevatorLock::End() {}

void ActuateElevatorLock::Interrupted() {}