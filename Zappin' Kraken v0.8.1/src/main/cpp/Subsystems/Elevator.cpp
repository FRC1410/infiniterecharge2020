#include "Subsystems/Elevator.h"
#include "Commands/Looped/RunElevator.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  m_elevator.RestoreFactoryDefaults();
  m_elevator.SetInverted(true);

  m_PID.SetP(elevator_kP);
  m_PID.SetI(elevator_kI);
  m_PID.SetD(elevator_kD);
}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new RunElevator);
}

void Elevator::SetSpeed(double speed) {
  frc::SmartDashboard::PutNumber("Elevator Power", speed);
  m_elevator.Set(speed);
}

void Elevator::SetPIDSpeed(double target) {
  m_PID.SetReference((target - kElevatorStartingHeight) / (kElevatorGearRatio * kElevatorPulleyDiameter * pi), rev::ControlType::kPosition);
}

double Elevator::GetHeight() {
  frc::SmartDashboard::PutNumber("Elevator Raw Ticks", m_encoder.GetPosition());
  return kElevatorStartingHeight + (m_encoder.GetPosition() * kElevatorGearRatio * kElevatorPulleyDiameter * pi);
}

void Elevator::SetLock(bool position) {
  m_lock.Set(position);
}

bool Elevator::GetLock() {
  return m_lock.Get();
}