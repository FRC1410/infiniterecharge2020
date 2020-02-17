#include "Commands/Actions/ActuateElevatorLock.h"
#include "Robot.h"

ActuateElevatorLock::ActuateElevatorLock() {
  Robot::m_elevator.SetLock(!Robot::m_elevator.GetLock());
}

ActuateElevatorLock::ActuateElevatorLock(bool position) {
  Robot::m_elevator.SetLock(position);
}

void ActuateElevatorLock::Initialize() {
}

void ActuateElevatorLock::Execute() {}

bool ActuateElevatorLock::IsFinished() {
  return true;
}

void ActuateElevatorLock::End() {}

void ActuateElevatorLock::Interrupted() {}