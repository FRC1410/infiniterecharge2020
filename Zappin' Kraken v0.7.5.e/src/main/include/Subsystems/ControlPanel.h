#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class ControlPanel : public frc::Subsystem {
  private:
    WPI_TalonSRX m_wheel{kControlPanelMotor};
    frc::DoubleSolenoid m_arm{kControlPanelSolenoidStart, kControlPanelSolenoidEnd};
    rev::ColorSensorV3 m_color_sensor{frc::I2C::Port::kOnboard};
    rev::ColorMatch m_color_matcher;
    frc::Color matched_color;

    bool isExtended = false;
    double confidence = 0;
    int color;
    std::string game_data;

  public:
    ControlPanel();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    int GetColor();
    int GetFMSData(int offset);
    void Raise();
    void Lower();
    bool GetPosition();
};