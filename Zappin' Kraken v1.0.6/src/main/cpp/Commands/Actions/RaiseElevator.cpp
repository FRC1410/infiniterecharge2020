#include "Commands/Actions/RaiseElevator.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

RaiseElevator::RaiseElevator(double target) {
  Requires(&Robot::m_elevator);
  target_height = target;
}

void RaiseElevator::Initialize() {
  Robot::m_elevator.SetBrake(false);
}

void RaiseElevator::Execute() {
  Robot::m_elevator.SetSpeed(kElevatorRaiseSpeed);
}

bool RaiseElevator::IsFinished() {
  return (Robot::m_elevator.GetHeight() > target_height);
}

void RaiseElevator::End() {
  Robot::m_elevator.SetSpeed(0);
  Robot::m_elevator.SetBrake(true);
}

void RaiseElevator::Interrupted() {
  End();
}