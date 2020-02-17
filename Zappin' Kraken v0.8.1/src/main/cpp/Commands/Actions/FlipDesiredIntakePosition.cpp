#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Robot.h"

FlipDesiredIntakePosition::FlipDesiredIntakePosition() {
  Robot::m_intake_flipper.SetDesiredPosition(!Robot::m_intake_flipper.GetDesiredPosition());
}

FlipDesiredIntakePosition::FlipDesiredIntakePosition(bool position) {
  Robot::m_intake_flipper.SetDesiredPosition(position);
}

void FlipDesiredIntakePosition::Initialize() {}

void FlipDesiredIntakePosition::Execute() {}

bool FlipDesiredIntakePosition::IsFinished() {
  return true;
}

void FlipDesiredIntakePosition::End() {}

void FlipDesiredIntakePosition::Interrupted() {}