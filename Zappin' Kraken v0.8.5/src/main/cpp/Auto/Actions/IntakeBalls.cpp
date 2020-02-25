#include "Auto/Actions/IntakeBalls.h"
#include "Robot.h"

IntakeBalls::IntakeBalls() {
  Requires(&Robot::m_intake);
}

IntakeBalls::IntakeBalls(double speed_input) {
  Requires(&Robot::m_intake);
  speed = speed_input;
}

void IntakeBalls::Initialize() {}

void IntakeBalls::Execute() {
  Robot::m_intake.SetSpeed(speed);
}

bool IntakeBalls::IsFinished() {
  return false;
}

void IntakeBalls::End() {
  Robot::m_intake.SetSpeed(0);
}

void IntakeBalls::Interrupted() {
  End();
}