#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Shooter : public frc::Subsystem {
  private:
    WPI_TalonFX m_shooter{kShooterMotor};

  public:
    Shooter();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    double GetSpeed();
    double GetRPM();
    void SetPIDSpeed(double target_RPM);
};