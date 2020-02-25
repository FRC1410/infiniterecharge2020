#include "Commands/Looped/RunIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {}

void RunIntake::Execute() {
  if (Robot::m_intake_flipper.GetDesiredPosition() == kIntakeFlipperDown) {
    Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis));
  } else {
    Robot::m_intake.SetSpeed(0);
  }
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}