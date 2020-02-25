#include "Subsystems/IntakeFlipper.h"
#include "Commands/Looped/FlipIntake.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

IntakeFlipper::IntakeFlipper() : Subsystem("ExampleSubsystem") {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");
  flipper_power_entry = table->GetEntry("Flipper Power");

  m_flipper.RestoreFactoryDefaults();
  m_flipper.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_flipper.SetInverted(false);

  m_PID.SetP(intake_flipper_kP);
  m_PID.SetI(intake_flipper_kI);
  m_PID.SetD(intake_flipper_kD);
  m_PID.SetFF(0);

  m_PID.SetOutputRange(kIntakeFlipperUpPowerCap, kIntakeFlipperDownPowerCap);
}

void IntakeFlipper::InitDefaultCommand() {
  SetDefaultCommand(new FlipIntake);
}

void IntakeFlipper::SetSpeed(double speed) {
  m_flipper.Set(speed);
  current_speed = speed;
  flipper_power_entry.SetDouble(speed);
}

void IntakeFlipper::ResetAngle() {
  m_encoder.SetPosition(kIntakeFlipperStartingAngle / (360 * kIntakeFlipperGearRatio));
}

double IntakeFlipper::GetAngle() {
  return (m_encoder.GetPosition() * 360 * kIntakeFlipperGearRatio);
}

void IntakeFlipper::SetDesiredPosition(int position) {
  desired_position = position;
}

int IntakeFlipper::GetDesiredPosition() {
  return desired_position;
}

void IntakeFlipper::SetPIDSpeed(double target) {
  m_PID.SetReference((target / kIntakeFlipperGearRatio) / 360, rev::ControlType::kPosition);
  current_speed = m_flipper.Get();
}

void IntakeFlipper::Accelerate(double target_speed, double time_difference) {
  if (abs(target_speed - current_speed) < (time_difference / kAccelerationTime)) {
    m_flipper.Set(target_speed);
  }
}