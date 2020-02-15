#include "Auto/Actions/IntakeBalls.h"
#include "Robot.h"

IntakeBalls::IntakeBalls() {
  Requires(&Robot::m_intake);
  time = -1;
}

IntakeBalls::IntakeBalls(double time_input) {
  Requires(&Robot::m_intake);
  time = time_input;
}

void IntakeBalls::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void IntakeBalls::Execute() {
  Robot::m_intake.SetSpeed(1);
}

bool IntakeBalls::IsFinished() {
  return ((m_timer.Get() / time) > 1);
}

void IntakeBalls::End() {
  Robot::m_intake.SetSpeed(0);
}

void IntakeBalls::Interrupted() {
  End();
}