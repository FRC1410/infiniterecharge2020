#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Feedback : public frc::Subsystem {
  private:
    frc::AnalogInput m_pressure{kPressureSensor};

  public:
    Feedback();
    void InitDefaultCommand() override;
    double GetPressure();
};
