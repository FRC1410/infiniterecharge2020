#include "Auto/Actions/IntakeBalls.h"
#include "Robot.h"

IntakeBalls::IntakeBalls() {
  Requires(&Robot::m_intake);
  speed = 1;
}

IntakeBalls::IntakeBalls(double speed_input) {
  Requires(&Robot::m_intake);
  speed = speed_input;
}

void IntakeBalls::Initialize() {}

void IntakeBalls::Execute() {
  Robot::m_intake.SetSpeed(speed);
  Robot::m_storage.SetAutonomouslyRunning(true);
}

bool IntakeBalls::IsFinished() {
  return (speed == 0);
}

void IntakeBalls::End() {
  Robot::m_intake.SetSpeed(0);
  Robot::m_storage.SetAutonomouslyRunning(false);
}

void IntakeBalls::Interrupted() {
  End();
}