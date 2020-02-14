#include "Commands/Actions/Shoot.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

Shoot::Shoot() {
  Requires(&Robot::m_storage);
}

void Shoot::Initialize() {
  Robot::m_storage.UnblockShooter();

  m_timer.Reset();
  m_timer.Start();
}

void Shoot::Execute() {
  Robot::m_storage.SetSpeed(kStorageFeedShooterHorizontalSpeed, kStorageFeedShooterVerticalSpeed);

  if (m_timer.Get() > kBallCountResetTime) {
    Robot::m_storage.SetBallCount(0);
  }
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