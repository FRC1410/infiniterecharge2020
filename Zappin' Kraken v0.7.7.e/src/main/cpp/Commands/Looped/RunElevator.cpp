#include "Commands/Looped/RunElevator.h"
#include "Robot.h"

RunElevator::RunElevator() {
  Requires(&Robot::m_elevator);
}

void RunElevator::Initialize() {}

void RunElevator::Execute() {}

bool RunElevator::IsFinished() {
  return false;
}

void RunElevator::End() {}

void RunElevator::Interrupted() {}