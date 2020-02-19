#include "Commands/Looped/RunIntake.h"
#include "Robot.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {}

void RunIntake::Execute() {
  if (Robot::m_intake_flipper.GetDesiredPosition() == true) {
<<<<<<< Updated upstream:Zappin' Kraken v0.8.2/src/main/cpp/Commands/Looped/RunIntake.cpp
    Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
=======
    Robot::m_intake.SetSpeed((Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis)) * kIntakeConstantLimiter);
>>>>>>> Stashed changes:Zappin' Kraken v0.7.7.e/src/main/cpp/Commands/Looped/RunIntake.cpp
  } else {
    Robot::m_intake.SetSpeed(0);
  }
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}