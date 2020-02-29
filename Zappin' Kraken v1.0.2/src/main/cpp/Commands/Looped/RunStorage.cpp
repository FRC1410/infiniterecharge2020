#include "Commands/Looped/RunStorage.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Tuning.h"

RunStorage::RunStorage() {
  Requires(&Robot::m_storage);
}

void RunStorage::Initialize() {
  Robot::m_storage.SetOuttakeRan(false);
  m_timer.Reset();
  m_timer.Stop();
  frc::SmartDashboard::PutNumber("Storage Delay", kStoragePhotoelectricDelay);
  frc::SmartDashboard::PutNumber("Storage Pre-Delay", 0);
}

void RunStorage::Execute() {
  if (Robot::m_storage.GetShooting() == false) {
    if (Robot::m_oi.GetOperatorButton(kStorageOuttakeButton) == true) {
      Robot::m_storage.SetVerticalSpeed(-kVerticalStorageSpeed);
      Robot::m_storage.SetOuttakeRan(true);
    } else if (Robot::m_oi.GetOperatorButton(kVerticalStorageButton) == true) {
      Robot::m_storage.SetVerticalSpeed(kVerticalStorageSpeed);
    } else if ((Robot::m_storage.GetManualControl() == true) || (Robot::m_storage.GetOuttakeRan() == true)) {
      Robot::m_storage.SetVerticalSpeed(0);
      Robot::m_storage.SetBallCount(0);
      m_timer.Reset();
      m_timer.Stop();
    } else {
      if (Robot::m_storage.GetBallCount() < 3) {
        if (Robot::m_storage.GetPhotoelectricSensor() == true) {
          m_timer.Reset();
          m_timer.Start();
        }
      } else {
        Robot::m_storage.SetVerticalSpeed(0);
      }

      if (m_timer.Get() > frc::SmartDashboard::GetNumber("Storage Delay", kStoragePhotoelectricDelay)) {
        Robot::m_storage.SetVerticalSpeed(0);
        Robot::m_storage.IncrementBallCount();
        m_timer.Reset();
        m_timer.Stop();
      } else if (m_timer.Get() > frc::SmartDashboard::GetNumber("Storage Pre-Delay", 0)) {
        Robot::m_storage.SetVerticalSpeed(kVerticalStorageSpeed);
      } else {
        Robot::m_storage.SetVerticalSpeed(0);
      }
    }

    if (Robot::m_oi.GetOperatorButton(kStorageOuttakeButton) == true) {
      Robot::m_storage.SetHorizontalSpeed(-kHorizontalStorageSpeed);
    } else if ((Robot::m_storage.GetAutonomouslyRunning() == true) && (Robot::m_storage.GetBallCount() <= 3)) {
      Robot::m_storage.SetHorizontalSpeed(kHorizontalStorageSpeed);
    } else if ((Robot::m_storage.GetBallCount() <= 3) || ((Robot::m_storage.GetManualControl() == true) || (Robot::m_storage.GetOuttakeRan() == true))) {
      Robot::m_storage.SetHorizontalSpeed(kHorizontalStorageSpeed * Robot::m_oi.GetOperatorAxis(kIntakeAxis));
    } else {
      Robot::m_storage.SetHorizontalSpeed(0);
    }

    if ((Robot::m_storage.GetBallCount() == 3) && (Robot::m_storage.GetPhotoelectricSensor() == true)) {
      Robot::m_storage.IncrementBallCount();
    }
  } else {
    Robot::m_storage.SetSpeed(kHorizontalStorageFeedShooterSpeed, kVerticalStorageFeedShooterSpeed);
  }
}

bool RunStorage::IsFinished() {
  return false;
}

void RunStorage::End() {}

void RunStorage::Interrupted() {}