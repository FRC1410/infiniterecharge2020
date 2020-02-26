#include "Commands/Looped/RunIntake.h"
#include "Robot.h"

RunIntake::RunIntake() {
  Requires(&Robot::m_intake);
}

void RunIntake::Initialize() {}

void RunIntake::Execute() {
<<<<<<< Updated upstream:Zappin' Kraken v0.7.7.e/src/main/cpp/Commands/Looped/RunIntake.cpp
  if (Robot::m_storage.GetBallCount() < 5) {
    Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
=======
  

  if (Robot::m_intake_flipper.GetDesiredPosition() == kIntakeFlipperDown) {
    if(Robot::m_oi.GetOperatorAxis(2) != 0 ) Robot::m_intake.SetSpeed(-1 * Robot::m_oi.GetOperatorAxis(2));
    if(Robot::m_oi.GetOperatorAxis(3) != 0 ) Robot::m_intake.SetSpeed(Robot::m_oi.GetOperatorAxis(3));
>>>>>>> Stashed changes:Zappin' Kraken v0.8.5.e/src/main/cpp/Commands/Looped/RunIntake.cpp
  } else {
    Robot::m_intake.SetSpeed(0);
  }
  
}

bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End() {}

void RunIntake::Interrupted() {}