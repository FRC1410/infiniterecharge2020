#include "Commands/Actions/Shoot.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

Shoot::Shoot() {
  Requires(&Robot::m_storage);
}

void Shoot::Initialize() {
  Robot::m_storage.UnblockShooter();
}

void Shoot::Execute() {
<<<<<<< Updated upstream:Zappin' Kraken v0.8.2/src/main/cpp/Commands/Actions/Shoot.cpp
  Robot::m_storage.SetSpeed(kStorageFeedShooterHorizontalSpeed, frc::SmartDashboard::GetNumber("Vertical Storage Speed", kStorageFeedShooterVerticalSpeed));
=======
  Robot::m_storage.SetSpeed(frc::SmartDashboard::GetNumber("Horizontal Storage Speed", kStorageFeedShooterHorizontalSpeed), frc::SmartDashboard::GetNumber("Vertical Storage Speed", kStorageFeedShooterVerticalSpeed));
>>>>>>> Stashed changes:Zappin' Kraken v0.7.7.e/src/main/cpp/Commands/Actions/Shoot.cpp
}

bool Shoot::IsFinished() {
  return false;
}

void Shoot::End() {
  Robot::m_storage.BlockShooter();
  Robot::m_storage.SetSpeed(0, 0);
}

void Shoot::Interrupted() {
  End();
}