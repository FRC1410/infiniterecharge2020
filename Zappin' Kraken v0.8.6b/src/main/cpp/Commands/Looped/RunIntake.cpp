#include "Commands/Looped/RunIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {
  trigger_was_pressed = ((Robot::m_oi.GetOperatorAxis(kIntakeAxis) > kOperatorTriggerThreshold) || (Robot::m_oi.GetOperatorAxis(kOuttakeAxis) > kOperatorTriggerThreshold));
}

void RunIntake::Execute() {
  if (((Robot::m_oi.GetOperatorAxis(kIntakeAxis) > kOperatorTriggerThreshold) || (Robot::m_oi.GetOperatorAxis(kOuttakeAxis) > kOperatorTriggerThreshold)) != trigger_was_pressed) {
    if ((Robot::m_oi.GetOperatorAxis(kIntakeAxis) > kOperatorTriggerThreshold) || (Robot::m_oi.GetOperatorAxis(kOuttakeAxis) > kOperatorTriggerThreshold)) {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperDown);
    } else {
      Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperUp);
    }
  }
  trigger_was_pressed = ((Robot::m_oi.GetOperatorAxis(kIntakeAxis) > kOperatorTriggerThreshold) || (Robot::m_oi.GetOperatorAxis(kOuttakeAxis) > kOperatorTriggerThreshold));
  Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}