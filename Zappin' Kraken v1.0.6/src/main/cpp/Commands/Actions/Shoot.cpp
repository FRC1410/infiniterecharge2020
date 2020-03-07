#include "Commands/Actions/Shoot.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

Shoot::Shoot() {}

void Shoot::Initialize() {}

void Shoot::Execute() {
  Robot::m_storage.SetShooting(true);
}

bool Shoot::IsFinished() {
  return false;
}

void Shoot::End() {
  Robot::m_storage.SetSpeed(0, 0);
  Robot::m_storage.SetBallCount(0);
  Robot::m_feedback.SetAligning(false);
  Robot::m_storage.SetShooting(false);
}

void Shoot::Interrupted() {
  End();
}