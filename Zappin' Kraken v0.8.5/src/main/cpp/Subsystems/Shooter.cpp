#include "Subsystems/Shooter.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem") {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  shooter_speed_entry = table->GetEntry("Shooter speed");

  m_shooter.ConfigFactoryDefault();
  m_shooter.SetNeutralMode(NeutralMode::Coast);
  m_shooter.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_shooter.SetInverted(true);
}

void Shooter::InitDefaultCommand() {}

void Shooter::SetPIDConstants(double kP, double kI, double kD, double kF) {
  m_shooter.Config_kP(kPrimaryPID, kP, kPIDTimeout);
  m_shooter.Config_kI(kPrimaryPID, kI, kPIDTimeout);
  m_shooter.Config_kD(kPrimaryPID, kD, kPIDTimeout);
  m_shooter.Config_kF(kPrimaryPID, kF, kPIDTimeout);
}

void Shooter::SetSpeed(double speed) {
  m_shooter.Set(ControlMode::PercentOutput, speed);
}

void Shooter::SetPIDSpeed(double target_RPM) {
  m_shooter.Set(ControlMode::Velocity, target_RPM / kFalconTicksToRPM);
  frc::SmartDashboard::PutNumber("Shooter speed", m_shooter.GetMotorOutputPercent());
}

double Shooter::GetRPM() {
  frc::SmartDashboard::PutNumber("Shooter Falon RPM", m_shooter.GetSelectedSensorVelocity(0) * 600 / 2048);
  return -m_shooter.GetSensorCollection().GetIntegratedSensorVelocity() * kFalconTicksToRPM;
}