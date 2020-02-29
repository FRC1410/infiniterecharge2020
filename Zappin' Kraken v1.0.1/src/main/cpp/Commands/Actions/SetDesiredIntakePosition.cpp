#include "Commands/Actions/SetDesiredIntakePosition.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

SetDesiredIntakePosition::SetDesiredIntakePosition(int position) {
  desired_position = position;
}

void SetDesiredIntakePosition::Initialize() {
  if (desired_position == kIntakeFlipperMid) {
    Robot::m_intake_flipper.SetDesiredPosition((Robot::m_intake_flipper.GetDesiredPosition() + 1) % 2);
  } else {
    Robot::m_intake_flipper.SetDesiredPosition(desired_position);
  }
}

void SetDesiredIntakePosition::Execute() {}

bool SetDesiredIntakePosition::IsFinished() {
  return true;
}

void SetDesiredIntakePosition::End() {}

void SetDesiredIntakePosition::Interrupted() {}