#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Storage : public frc::Subsystem {
  private:
    WPI_TalonSRX m_storage_horizontal_left{kHorizontalStorageLeftMotor}, m_storage_horizontal_right{kHorizontalStorageRightMotor};
    WPI_TalonSRX m_storage_vertical_front{kVerticalStorageFrontMotor}, m_storage_vertical_back{kVerticalStorageBackMotor};

    frc::DoubleSolenoid m_blocker{kStorageSolenoidStart, kStorageSolenoidEnd};
    frc::DigitalInput m_photoelectric{kPhotoelectricPort}, m_photoelectric2{1};

    int ball_count = 0;

    nt::NetworkTableEntry vertical_power_entry;

    bool manual_control;

  public:
    Storage();
    void InitDefaultCommand() override;
    void SetHorizontalSpeed(double speed);
    void SetVerticalSpeed(double speed);
    void SetSpeed(double horizontal_speed, double vertical_speed);
    bool GetPhotoelectricSensor();
    bool GetPhotoelectricSensor2();
    int GetBallCount();
    void IncrementBallCount();
    void SetBallCount(int interval);
    void SetBlocker(frc::DoubleSolenoid::Value position);
    frc::DoubleSolenoid::Value GetBlockerPosition();
    void SetManualControl(bool manual);
    bool GetManualControl();
};