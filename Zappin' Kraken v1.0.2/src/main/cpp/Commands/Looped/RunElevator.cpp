#include "Commands/Looped/RunElevator.h"
#include "Robot.h"

RunElevator::RunElevator() {
  Requires(&Robot::m_elevator);
}

void RunElevator::Initialize() {
  joystick_was_moved = (Robot::m_oi.GetOperatorAxis(kElevatorAxis) != 0);
}

void RunElevator::Execute() {
  if (joystick_was_moved == (Robot::m_oi.GetOperatorAxis(kElevatorAxis) == 0)) {
    Robot::m_elevator.SetBrake(Robot::m_oi.GetOperatorAxis(kElevatorAxis) == 0);
  }
  joystick_was_moved = (Robot::m_oi.GetOperatorAxis(kElevatorAxis) != 0);
  Robot::m_elevator.SetSpeed(Robot::m_oi.GetOperatorAxis(kElevatorAxis));
}

bool RunElevator::IsFinished() {
  return false;
}

void RunElevator::End() {}

void RunElevator::Interrupted() {}