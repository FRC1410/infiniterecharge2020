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
  follow_through = false;
  m_timer.Reset();
  m_timer.Stop();
  storage_sequence = 0;
}

void RunStorage::Execute() {
  if (Robot::m_storage.GetOuterUltrasonicSensor() == true) {
    if (outer_sensor_was_read == false) {
      storage_sequence = 1;
      Robot::m_storage.SetSpeed(kStorageHorizontalSpeed, frc::SmartDashboard::GetNumber("Vertical Storage Speed", kStorageFeedShooterVerticalSpeed));
      Robot::m_storage.IncrementBallCount();
    }
    outer_sensor_was_read = true;
      m_timer.Reset();
      m_timer.Start();
  } else {
    follow_through = true;
    if (outer_sensor_was_read == true) {
      m_timer.Reset();
      m_timer.Start();
    }
    outer_sensor_was_read = false;
  }

  if (m_timer.Get() > 0.254 && follow_through == true) {
    follow_through = false;
    Robot::m_storage.SetSpeed(0,0);
  }



  /*if (Robot::m_storage.GetInnerUltrasonicSensor() == true) {
    if (inner_sensor_was_read == false && storage_sequence == 1) {
      storage_sequence = 2;
    }
    inner_sensor_was_read = true;
  } else {
    if (inner_sensor_was_read == true && storage_sequence == 2) {
      Robot::m_storage.SetSpeed(0, 0);
      storage_sequence = 0;
    }
    inner_sensor_was_read = false;
  }
  frc::SmartDashboard::PutNumber("Sequence", storage_sequence);*/
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}