#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Elevator : public frc::Subsystem {
  private:
    rev::CANSparkMax m_elevator{kElevatorMotor, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANEncoder m_encoder = m_elevator.GetEncoder();
    rev::CANPIDController m_PID = m_elevator.GetPIDController();
    frc::Solenoid m_lock{kElevatorSolenoid};

  public:
    Elevator();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    double GetRawPosition();
    void LockElevator();
    void UnlockElevator();
    bool GetElevatorLock();
};