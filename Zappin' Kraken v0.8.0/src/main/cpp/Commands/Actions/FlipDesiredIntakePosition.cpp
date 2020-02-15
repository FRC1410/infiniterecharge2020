#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Robot.h"

FlipDesiredIntakePosition::FlipDesiredIntakePosition() {}

void FlipDesiredIntakePosition::Initialize() {
  Robot::m_intake_flipper.SetDesiredPosition(!Robot::m_intake_flipper.GetDesiredPosition());
}

void FlipDesiredIntakePosition::Execute() {}

bool FlipDesiredIntakePosition::IsFinished() {
  return true;
}

void FlipDesiredIntakePosition::End() {}

void FlipDesiredIntakePosition::Interrupted() {}