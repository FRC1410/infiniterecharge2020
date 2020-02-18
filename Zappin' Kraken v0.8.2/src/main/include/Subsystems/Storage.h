#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Storage : public frc::Subsystem {
  private:
    WPI_TalonSRX m_storage_horizontal_left{kHorizontalStorageLeftMotor}, m_storage_horizontal_right{kHorizontalStorageRightMotor};
    WPI_TalonSRX m_storage_vertical_front{kVerticalStorageFrontMotor}, m_storage_vertical_back{kVerticalStorageBackMotor};

    frc::DoubleSolenoid m_blocker{kStorageSolenoidStart, kStorageSolenoidEnd};
    frc::DigitalInput m_photoelectric_out{kPhotoelectricOuterPort}, m_photoelectric_in{kPhotoelectricInnerPort};

    int ball_count = 0;

    nt::NetworkTableEntry vertical_power_entry;

  public:
    Storage();
    void InitDefaultCommand() override;
    void SetSpeed(double horizontal_speed, double vertical_speed);
    bool GetOuterUltrasonicSensor();
    bool GetInnerUltrasonicSensor();
    int GetBallCount();
    void IncrementBallCount();
    void SetBallCount(int interval);
    void BlockShooter();
    void UnblockShooter();
    bool GetBlockerPosition();
};