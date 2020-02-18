#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Robot.h"

FlipDesiredIntakePosition::FlipDesiredIntakePosition() {
  has_desired_position = false;
}

FlipDesiredIntakePosition::FlipDesiredIntakePosition(bool position) {
  has_desired_position = true;
  desired_position = position;
}

void FlipDesiredIntakePosition::Initialize() {
  if (has_desired_position == true) {
    Robot::m_intake_flipper.SetDesiredPosition(desired_position);
  } else {
    Robot::m_intake_flipper.SetDesiredPosition(!Robot::m_intake_flipper.GetDesiredPosition());
  }}

void FlipDesiredIntakePosition::Execute() {}

bool FlipDesiredIntakePosition::IsFinished() {
  return true;
}

void FlipDesiredIntakePosition::End() {}

void FlipDesiredIntakePosition::Interrupted() {}