#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class IntakeFlipper : public frc::Subsystem {
  private:
    rev::CANSparkMax m_flipper{kIntakeFlipperMotor, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANEncoder m_encoder = m_flipper.GetEncoder();
    rev::CANPIDController m_PID = m_flipper.GetPIDController();

    double current_speed = 0;
    bool down = false;
    nt::NetworkTableEntry flipper_power_entry;

  public:
    IntakeFlipper();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    void ResetAngle();
    double GetAngle();
    void SetDesiredPosition(bool position);
    bool GetDesiredPosition();
    void SetPIDConstants(double kP, double kI, double kD);
    void SetPIDSpeed(double target, double kF);
    void Accelerate(double target_speed, double time_difference);
};