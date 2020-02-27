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
  m_timer.Start();
  disabled_was_pressed = (Robot::m_oi.GetOperatorDPad() == 270);
  Robot::m_storage.SetBallCount(0);

  m_measure_timer.Reset();
  m_measure_timer.Stop();
}

void RunStorage::Execute() {
  if (Robot::m_oi.GetOperatorDPad() == 270) {
    if (disabled_was_pressed == false) {
      Robot::m_storage.SetManualControl(!Robot::m_storage.GetManualControl());
    }
    disabled_was_pressed = true;
  } else {
    disabled_was_pressed = false;
  }


  if (Robot::m_storage.GetPhotoelectricSensor() == true && sensor_was_read == false) {
    m_measure_timer.Reset();
    m_measure_timer.Start();
  }

  if (Robot::m_storage.GetPhotoelectricSensor() == false) {
    m_measure_timer.Stop();
  }

  frc::SmartDashboard::PutNumber("Sensor Interval", m_measure_timer.Get());

  if (Robot::m_storage.GetManualControl() == false && Robot::m_storage.GetBallCount() < 3/* && Robot::m_storage.GetPhotoelectricSensor2() == false*/) {
    if (Robot::m_storage.GetPhotoelectricSensor() == true) {
      if (sensor_was_read == false) {
        Robot::m_storage.SetVerticalSpeed(kStorageVerticalSpeed);
      }
      sensor_was_read = true;
      m_timer.Reset();
    } else {
      if (sensor_was_read == true) {
        follow_through = true;
        m_timer.Reset();
      }
      sensor_was_read = false;
    }
  } else {
    Robot::m_storage.SetVerticalSpeed(0);
    //Robot::m_storage.SetVerticalSpeed(kStorageVerticalSpeed * Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
  }

  if ((m_timer.Get() > kStoragePhotoelectricDelay) && (follow_through == true)) {
    follow_through = false;
    Robot::m_storage.SetVerticalSpeed(0);
    Robot::m_storage.IncrementBallCount();
  }

  if (Robot::m_storage.GetBallCount() > 3) {
    Robot::m_storage.SetHorizontalSpeed(0);
  } else {
    if (Robot::m_storage.GetPhotoelectricSensor() == true && Robot::m_storage.GetBallCount() == 3) {
      Robot::m_storage.IncrementBallCount();
    } else {
      Robot::m_storage.SetHorizontalSpeed(kStorageHorizontalSpeed * Robot::m_oi.GetOperatorAxis(kOuttakeAxis));
    }
  }
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}