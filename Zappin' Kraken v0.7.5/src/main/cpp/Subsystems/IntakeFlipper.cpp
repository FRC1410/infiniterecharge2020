#include "Subsystems/IntakeFlipper.h"
#include "Commands/Looped/FlipIntake.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

IntakeFlipper::IntakeFlipper() : Subsystem("ExampleSubsystem") {
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
  frc::SmartDashboard::PutNumber("Flipper Power", speed);
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

void IntakeFlipper::SetPIDSpeed(double target, double kF) {
  m_PID.SetFF(kF);
  m_PID.SetReference(target / kNEOTicksToDegrees, rev::ControlType::kPosition);
}