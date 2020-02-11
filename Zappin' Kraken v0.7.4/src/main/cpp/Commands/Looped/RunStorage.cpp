#include "Commands/Looped/RunStorage.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Tuning.h"

RunStorage::RunStorage() {
  Requires(&Robot::m_storage);
}

void RunStorage::Initialize() {
  outer_sensor_was_read = false;
  inner_sensor_was_read = false;
  //Robot::m_storage.SetSpeed(0, 0);
}

void RunStorage::Execute() {
  /*if (Robot::m_storage.GetInnerUltrasonicSensor() == true) {
    if (inner_sensor_was_read == false) {
      Robot::m_storage.SetSpeed(0, 0);
    }
    inner_sensor_was_read = true;
  } else {
    inner_sensor_was_read = false;
  }

  if (Robot::m_storage.GetOuterUltrasonicSensor() == true) {
    if (outer_sensor_was_read == false) {
      Robot::m_storage.SetSpeed(kStorageHorizontalSpeed, kStorageVerticalSpeed);
      Robot::m_storage.IncrementBallCount();
    }
    outer_sensor_was_read = true;
  } else {
    outer_sensor_was_read = false;
  }*/
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}