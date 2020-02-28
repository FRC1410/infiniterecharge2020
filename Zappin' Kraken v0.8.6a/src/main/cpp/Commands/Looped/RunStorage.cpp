#include "Commands/Looped/RunStorage.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Tuning.h"

RunStorage::RunStorage() {
  Requires(&Robot::m_storage);
}

void RunStorage::Initialize() {
  sensor_was_read = false;
  follow_through = false;

  m_timer.Reset();
  m_timer.Stop();
}

void RunStorage::Execute() {
  if (Robot::m_storage.GetManualControl() == false && Robot::m_storage.GetBallCount() < 3) {
    if (Robot::m_storage.GetPhotoelectricSensor() == true) {
      if (sensor_was_read == false) {
        Robot::m_storage.SetVerticalSpeed(kVerticalStorageSpeed);
      }
      m_timer.Reset();
      m_timer.Start();
    } else {
      follow_through = true;
      if (sensor_was_read == true) {
        m_timer.Reset();
        m_timer.Start();
      }
    }
    sensor_was_read = Robot::m_storage.GetPhotoelectricSensor();
  } else {
    Robot::m_storage.SetVerticalSpeed(0);
  }

  if ((m_timer.Get() > kStoragePhotoelectricDelay) && (follow_through == true)) {
    follow_through = false;
    Robot::m_storage.SetVerticalSpeed(0);
    Robot::m_storage.IncrementBallCount();
    m_timer.Reset();
    m_timer.Stop();
  }

  if (Robot::m_oi.GetOperatorButton(kVerticalStorageButton) == true) {
    Robot::m_storage.SetVerticalSpeed(kVerticalStorageSpeed);
  }

  if (Robot::m_storage.GetBallCount() > 3) {
    Robot::m_storage.SetHorizontalSpeed(0);
  } else if ((Robot::m_storage.GetBallCount() == 3) && (Robot::m_storage.GetPhotoelectricSensor() == true)) {
    Robot::m_storage.IncrementBallCount();
  }

  if ((Robot::m_storage.GetManualControl() == true) || (Robot::m_storage.GetBallCount() <= 3)) {
    if (Robot::m_oi.GetOperatorButton(kHorizontalStorageButton) == true) {
      Robot::m_storage.SetHorizontalSpeed(kHorizontalStorageSpeed);
    } else {
      Robot::m_storage.SetHorizontalSpeed(0);
    }
  }

  if (Robot::m_oi.GetOperatorButton(kStorageOuttakeButton) == true) {
    Robot::m_storage.SetSpeed(-kHorizontalStorageSpeed, -kVerticalStorageSpeed);
  }
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}