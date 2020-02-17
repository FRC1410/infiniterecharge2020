#include "Commands/Looped/RunStorage.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Tuning.h"

RunStorage::RunStorage() {
  Requires(&Robot::m_storage);
}

void RunStorage::Initialize() {}

void RunStorage::Execute() {
  speed_input = Robot::m_oi.GetOperatorAxis(kIntakeAxis) - Robot::m_oi.GetOperatorAxis(kOuttakeAxis);
  Robot::m_storage.SetSpeed(kStorageHorizontalSpeed * speed_input, kStorageVerticalSpeed * speed_input);
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}