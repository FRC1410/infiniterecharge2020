#include "Subsystems/Shooter.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem") {
  m_shooter.ConfigFactoryDefault();
  m_shooter.SetNeutralMode(NeutralMode::Coast);
  m_shooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_shooter.SetInverted(true);

  m_shooter.Config_kP(kPrimaryPID, shooter_kP, kPIDTimeout);
  m_shooter.Config_kI(kPrimaryPID, shooter_kI, kPIDTimeout);
  m_shooter.Config_kD(kPrimaryPID, shooter_kD, kPIDTimeout);
  m_shooter.Config_kF(kPrimaryPID, shooter_kF, kPIDTimeout);
}

void Shooter::InitDefaultCommand() {}

void Shooter::SetSpeed(double speed) {
  m_shooter.Set(ControlMode::PercentOutput, speed);
}

double Shooter::GetSpeed() {
  return m_shooter.GetMotorOutputPercent();
}

double Shooter::GetRPM() {
  return m_shooter.GetSelectedSensorVelocity(kPrimaryPID) * kFalconTicksToRPM;
}

void Shooter::SetPIDSpeed(double target_RPM) {
  m_shooter.Set(ControlMode::Velocity, target_RPM / kFalconTicksToRPM);
}