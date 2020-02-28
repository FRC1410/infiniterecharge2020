#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Shooter : public frc::Subsystem {
  private:
    WPI_TalonFX m_shooter{kShooterMotor};
    nt::NetworkTableEntry shooter_speed_entry;

  public:
    Shooter();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    double GetRPM();
    void SetPIDSpeed(double target_RPM);
};