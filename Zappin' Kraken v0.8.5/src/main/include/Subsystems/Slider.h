#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Slider : public frc::Subsystem {
  private:
    WPI_TalonSRX m_slider{kSliderMotor};

  public:
    Slider();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
};