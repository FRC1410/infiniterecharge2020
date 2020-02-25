#include "Commands/Looped/FlipIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FlipIntake::FlipIntake() {
  Requires(&Robot::m_intake_flipper);
}

void FlipIntake::Initialize() {}

void FlipIntake::Execute() {
  switch (Robot::m_intake_flipper.GetDesiredPosition()) {
    case kIntakeFlipperUp:
      if (Robot::m_intake_flipper.GetAngle() > kIntakeUpThreshold) {
        Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget);
      } else {
        Robot::m_intake_flipper.SetSpeed(0);
      }
      break;
    case kIntakeFlipperMid:
      Robot::m_intake_flipper.SetPIDSpeed(kIntakeMidTarget);
      break;
    case kIntakeFlipperDown:
      if (Robot::m_intake_flipper.GetAngle() < kIntakeDownThreshold) {
        Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget);
      } else {
        Robot::m_intake_flipper.SetSpeed(0);
      }
      break;
  }
}

bool FlipIntake::IsFinished() {
  return false;
}

void FlipIntake::End() {}

void FlipIntake::Interrupted() {}