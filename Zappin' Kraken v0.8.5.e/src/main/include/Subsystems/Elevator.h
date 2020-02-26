#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Elevator : public frc::Subsystem {
  private:
    rev::CANSparkMax m_elevator{kElevatorMotor, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANEncoder m_encoder = m_elevator.GetEncoder();
    rev::CANPIDController m_PID = m_elevator.GetPIDController();
    frc::Solenoid m_lock{kElevatorSolenoid};

    bool activated;

  public:
    Elevator();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    void SetPIDSpeed(double target);
    double GetHeight();
    void SetLock(bool position);
    bool GetLock();
    void SetActivated(bool activated_input);
    bool GetActivated();
};