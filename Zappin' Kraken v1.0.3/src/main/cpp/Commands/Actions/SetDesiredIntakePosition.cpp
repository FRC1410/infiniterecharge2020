#include "Commands/Actions/SetDesiredIntakePosition.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

SetDesiredIntakePosition::SetDesiredIntakePosition(int position) {
  desired_position = position;
}

void SetDesiredIntakePosition::Initialize() {
  if (desired_position <= kIntakeFlipperDown) {
    Robot::m_intake_flipper.SetDesiredPosition(desired_position);
  } else if (desired_position == kIntakeFlipperToggle) {
    if (Robot::m_intake_flipper.GetDesiredPosition() <= kIntakeFlipperMid) {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperDown);
    } else {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperUp);
    }
  } else if (desired_position == kIntakeFlipperMidToggle) {
    Robot::m_intake_flipper.SetDesiredPosition((Robot::m_intake_flipper.GetDesiredPosition() + 1) % 2);
  }
}

void SetDesiredIntakePosition::Execute() {}

bool SetDesiredIntakePosition::IsFinished() {
  return true;
}

void SetDesiredIntakePosition::End() {}

void SetDesiredIntakePosition::Interrupted() {}