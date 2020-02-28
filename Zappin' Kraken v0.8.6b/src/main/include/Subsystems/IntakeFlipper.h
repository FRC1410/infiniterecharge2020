#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class IntakeFlipper : public frc::Subsystem {
  private:
    rev::CANSparkMax m_flipper{kIntakeFlipperMotor, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANEncoder m_encoder = m_flipper.GetEncoder();
    rev::CANPIDController m_PID = m_flipper.GetPIDController();

    int desired_position = 0;

  public:
    IntakeFlipper();
    void InitDefaultCommand() override;
    void SetSpeed(double speed);
    void ResetAngle();
    double GetAngle();
    void SetDesiredPosition(int position);
    int GetDesiredPosition();
    void SetPIDSpeed(double target);
};