#include "Commands/Looped/RunElevator.h"
#include "Robot.h"

RunElevator::RunElevator() {
  Requires(&Robot::m_elevator);
}

void RunElevator::Initialize() {}

void RunElevator::Execute() {
  if (Robot::m_oi.GetOperatorAxis(kElevatorAxis) != 0 && Robot::m_elevator.GetActivated() == false) {
    Robot::m_elevator.SetLock(false);
    Robot::m_elevator.SetActivated(true);
  }
  Robot::m_elevator.SetSpeed(Robot::m_oi.GetOperatorAxis(kElevatorAxis));
  frc::SmartDashboard::PutNumber("Elevator Height", Robot::m_elevator.GetHeight());
}

bool RunElevator::IsFinished() {
  return false;
}

void RunElevator::End() {}

void RunElevator::Interrupted() {}