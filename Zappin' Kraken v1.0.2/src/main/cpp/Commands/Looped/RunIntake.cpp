#include "Commands/Looped/RunIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {}

void RunIntake::Execute() {
  Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}