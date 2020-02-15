#include "Subsystems/IntakeFlipper.h"
#include "Commands/Looped/FlipIntake.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

IntakeFlipper::IntakeFlipper() : Subsystem("ExampleSubsystem") {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");
  flipper_power_entry = table->GetEntry("Flipper Power");

  m_flipper.RestoreFactoryDefaults();
  m_flipper.SetInverted(false);

  m_PID.SetP(intake_flipper_kP);
  m_PID.SetI(intake_flipper_kI);
  m_PID.SetD(intake_flipper_kD);

  m_PID.SetOutputRange(kIntakeFlipperUpPowerCap, kIntakeFlipperDownPowerCap);
}

void IntakeFlipper::InitDefaultCommand() {
  SetDefaultCommand(new FlipIntake);
}

void IntakeFlipper::SetSpeed(double speed) {
  m_flipper.Set(speed);
  current_speed = speed;
  //frc::SmartDashboard::PutNumber("Flipper Power", speed);
  flipper_power_entry.SetDouble(speed);
}

void IntakeFlipper::ResetAngle() {
  m_encoder.SetPosition(kIntakeFlipperStartingAngle / (360 * kIntakeFlipperGearRatio));
}

double IntakeFlipper::GetAngle() {
  return (m_encoder.GetPosition() * 360 * kIntakeFlipperGearRatio);
}

void IntakeFlipper::SetDesiredPosition(bool position) {
  down = position;
}

bool IntakeFlipper::GetDesiredPosition() {
  return down;
}

void IntakeFlipper::SetPIDConstants(double kP, double kI, double kD) {
  m_PID.SetP(kP);
  m_PID.SetI(kI);
  m_PID.SetD(kD);
}

void IntakeFlipper::SetPIDSpeed(double target, double kF) {
  m_PID.SetFF(kF);
  m_PID.SetReference((target / kIntakeFlipperGearRatio) / 360, rev::ControlType::kPosition);
  current_speed = m_flipper.Get();
  frc::SmartDashboard::PutNumber("Flipper Power", current_speed);
  frc::SmartDashboard::PutNumber("Feedforward", kF);
}

void IntakeFlipper::Accelerate(double target_speed, double time_difference) {
  if (abs(target_speed - current_speed) < (time_difference / kAccelerationTime)) {
    m_flipper.Set(target_speed);
  }
}