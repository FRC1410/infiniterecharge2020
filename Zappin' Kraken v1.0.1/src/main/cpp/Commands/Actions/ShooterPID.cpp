#include "Commands/Actions/ShooterPID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

ShooterPID::ShooterPID() {
  Requires(&Robot::m_shooter);
  run = true;
}

ShooterPID::ShooterPID(bool run_input) {
  Requires(&Robot::m_shooter);
  run = run_input;
}

void ShooterPID::Initialize() {
  //Robot::m_storage.SetBallCount(0);
  Robot::m_storage.SetOuttakeRan(false);
}

void ShooterPID::Execute() {
  Robot::m_shooter.SetPIDSpeed(Robot::m_limelight.GetNearestRPMProfile());
}

bool ShooterPID::IsFinished() {
  return !run;
}

void ShooterPID::End() {
  Robot::m_shooter.SetSpeed(0);
}

void ShooterPID::Interrupted() {
  End();
}