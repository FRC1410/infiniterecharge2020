#include "Subsystems/Elevator.h"

Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  m_elevator.RestoreFactoryDefaults();
  m_elevator.SetInverted(false);
}

void Elevator::InitDefaultCommand() {}

void Elevator::SetSpeed(double speed) {
  m_elevator.Set(speed);
}

double Elevator::GetRawPosition() {
  return m_encoder.GetPosition();
}

void Elevator::LockElevator() {
  m_lock.Set(true);
}

void Elevator::UnlockElevator() {
  m_lock.Set(false);
}

bool Elevator::GetElevatorLock() {
  return m_lock.Get();
}