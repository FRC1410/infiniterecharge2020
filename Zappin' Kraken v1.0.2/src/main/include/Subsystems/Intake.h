#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Intake : public frc::Subsystem {
  private:
    WPI_VictorSPX m_intake{kIntakeMotor};

  public:
    Intake();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
};