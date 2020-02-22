#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

FlipDesiredIntakePosition::FlipDesiredIntakePosition() {
  has_desired_position = false;
}

FlipDesiredIntakePosition::FlipDesiredIntakePosition(int position) {
  has_desired_position = true;
  desired_position = position;
}

void FlipDesiredIntakePosition::Initialize() {
  if (has_desired_position == true) {
    Robot::m_intake_flipper.SetDesiredPosition(desired_position);
  } else {
    if (Robot::m_intake_flipper.GetDesiredPosition() > kIntakeFlipperUp) {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperUp);
    } else {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperDown);
    }
  }
}

void FlipDesiredIntakePosition::Execute() {}

bool FlipDesiredIntakePosition::IsFinished() {
  return true;
}

void FlipDesiredIntakePosition::End() {}

void FlipDesiredIntakePosition::Interrupted() {}