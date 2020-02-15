#include "Auto/Actions/ActivateStorage.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

ActivateStorage::ActivateStorage() {
  Requires(&Robot::m_storage);
  time = -1;
}

ActivateStorage::ActivateStorage(double time_input) {
  Requires(&Robot::m_storage);
  time = time_input;
}

void ActivateStorage::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void ActivateStorage::Execute() {
  Robot::m_storage.SetSpeed(kStorageHorizontalSpeed, kStorageVerticalSpeed);
}

bool ActivateStorage::IsFinished() {
  return ((m_timer.Get() / time) > 1);
}

void ActivateStorage::End() {
  Robot::m_storage.SetSpeed(0, 0);
}

void ActivateStorage::Interrupted() {
  End();
}