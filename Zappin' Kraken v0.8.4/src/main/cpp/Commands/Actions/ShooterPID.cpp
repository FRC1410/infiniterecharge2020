#include "Commands/Actions/ShooterPID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

ShooterPID::ShooterPID() {
  Requires(&Robot::m_shooter);
  target_RPM = -1;
}

ShooterPID::ShooterPID(double target_RPM_input) {
  Requires(&Robot::m_shooter);
  target_RPM = target_RPM_input;
}

void ShooterPID::Initialize() {
  if (target_RPM == 0) {
    End();
  } else if (target_RPM < 0) {
    target_RPM = Robot::m_limelight.GetNearestRPMProfile();
  }
  Robot::m_shooter.SetPIDConstants(shooter_kP, shooter_kI, shooter_kD, shooter_kF);
}

void ShooterPID::Execute() {
  Robot::m_shooter.SetPIDSpeed(target_RPM);
}

bool ShooterPID::IsFinished() {
  return false;
}

void ShooterPID::End() {
  Robot::m_shooter.SetSpeed(0);
}

void ShooterPID::Interrupted() {
  End();
}