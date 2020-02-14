#include "Subsystems/Elevator.h"

Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  m_elevator.RestoreFactoryDefaults();
  m_elevator.SetInverted(false);
}

void Elevator::InitDefaultCommand() {}

void Elevator::SetSpeed(double speed) {
  m_elevator.Set(speed);
}

void Elevator::Toggle() {
  m_brake.Set(!m_brake.Get());
}

double Elevator::GetRawPosition() {
  return m_encoder.GetPosition();
}