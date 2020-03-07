#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class ControlPanel : public frc::Subsystem {
  private:
    WPI_VictorSPX m_wheel{kControlPanelMotor};
    rev::ColorSensorV3 m_color_sensor{frc::I2C::Port::kOnboard};
    rev::ColorMatch m_color_matcher;
    frc::Color matched_color;

    double confidence = 0;
    int color;
    std::string game_data;

  public:
    ControlPanel();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    int GetColor();
    int GetFMSData(int offset);
};