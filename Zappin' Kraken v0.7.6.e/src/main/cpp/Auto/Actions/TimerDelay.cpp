#include "Auto/Actions/TimerDelay.h"
#include "Robot.h"

TimerDelay::TimerDelay(double input) {
  delay = input;
}

void TimerDelay::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void TimerDelay::Execute() {}

bool TimerDelay::IsFinished() {
  return (m_timer.Get() >= delay);
}

void TimerDelay::End() {}

void TimerDelay::Interrupted() {}