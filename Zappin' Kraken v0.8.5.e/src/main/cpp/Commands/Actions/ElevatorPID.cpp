#include "Commands/Actions/ElevatorPID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

ElevatorPID::ElevatorPID(double target) {
  Requires(&Robot::m_elevator);
  target_height = target;
}

void ElevatorPID::Initialize() {
  if (target_height == kElevatorUpTarget) {
    Robot::m_elevator.SetLock(false);
  }
}

void ElevatorPID::Execute() {
  Robot::m_elevator.SetPIDSpeed(target_height);
}

bool ElevatorPID::IsFinished() {
  return (abs(Robot::m_elevator.GetHeight() - target_height) < kElevatorFinishedThreshold);
}

void ElevatorPID::End() {
  Robot::m_elevator.SetSpeed(0);
  if (target_height == kElevatorDownTarget) {
    Robot::m_elevator.SetLock(true);
  }
}

void ElevatorPID::Interrupted() {
  End();
}