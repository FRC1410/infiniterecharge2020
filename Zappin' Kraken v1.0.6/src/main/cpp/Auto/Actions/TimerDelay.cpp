#include "Auto/Actions/TimerDelay.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

TimerDelay::TimerDelay() {
  type = 0;
}

TimerDelay::TimerDelay(int delay_type) {
  type = delay_type;
}

void TimerDelay::Initialize() {}

void TimerDelay::Execute() {}

bool TimerDelay::IsFinished() {
  switch (type) {
    case kShootDelay1:
      return (Robot::m_feedback.GetMatchTime() < (kAutoLength - Robot::m_feedback.auto_shoot_delay_1.GetDouble(0)));
      break;
    case kShootDelay2:
      return (Robot::m_feedback.GetMatchTime() < (kAutoLength - Robot::m_feedback.auto_shoot_delay_2.GetDouble(0)));
      break;
    default:
      return false;
  }
}

void TimerDelay::End() {}

void TimerDelay::Interrupted() {}