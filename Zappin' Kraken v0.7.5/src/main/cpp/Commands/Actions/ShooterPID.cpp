#include "Commands/Actions/ShooterPID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

ShooterPID::ShooterPID(double target_RPM_input) {
  Requires(&Robot::m_shooter);
  target_RPM = target_RPM_input;
}

void ShooterPID::Initialize() {
  Robot::m_shooter.SetPIDConstants(shooter_kP, shooter_kI, shooter_kD, shooter_kF);
}

void ShooterPID::Execute() {
  //Robot::m_shooter.SetSpeed(1);
  Robot::m_shooter.SetPIDSpeed(frc::SmartDashboard::GetNumber("Target RPM", kShooterRPMProfiles[2]));
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