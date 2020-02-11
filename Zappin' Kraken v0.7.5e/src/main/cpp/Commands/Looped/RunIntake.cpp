#include "Commands/Looped/RunIntake.h"
#include "Robot.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {}

void RunIntake::Execute() {
  if (Robot::m_storage.GetBallCount() < 5) {
    Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
  } else {
    Robot::m_intake.SetSpeed(0);
  }
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}