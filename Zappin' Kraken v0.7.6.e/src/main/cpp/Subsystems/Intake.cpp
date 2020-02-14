#include "Subsystems/Intake.h"
#include "Commands/Looped/RunIntake.h"
#include "RobotMap/Tuning.h"

Intake::Intake() : Subsystem("ExampleSubsystem") {
  m_intake.ConfigFactoryDefault();
  m_intake.SetNeutralMode(NeutralMode::Brake);
  m_intake.SetInverted(false);
}

void Intake::InitDefaultCommand() {
  SetDefaultCommand(new RunIntake);
}

void Intake::SetSpeed(double speed) {
  m_intake.Set(speed * kIntakeSpeedAdjustment);
}