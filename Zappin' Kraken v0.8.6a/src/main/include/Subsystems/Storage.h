#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Storage : public frc::Subsystem {
  private:
    WPI_TalonSRX m_storage_horizontal_left{kHorizontalStorageLeftMotor}, m_storage_horizontal_right{kHorizontalStorageRightMotor};
    WPI_TalonSRX m_storage_vertical_front{kVerticalStorageFrontMotor}, m_storage_vertical_back{kVerticalStorageBackMotor};

    frc::DigitalInput m_photoelectric{kPhotoelectricPort};

    int ball_count;
    bool manual_control = false;

  public:
    Storage();
    void InitDefaultCommand() override;
    void SetHorizontalSpeed(double speed);
    void SetVerticalSpeed(double speed);
    void SetSpeed(double horizontal_speed, double vertical_speed);
    bool GetPhotoelectricSensor();
    void SetBallCount(int count);
    int GetBallCount();
    void IncrementBallCount();
    void SetManualControl(bool manual);
    bool GetManualControl();
};