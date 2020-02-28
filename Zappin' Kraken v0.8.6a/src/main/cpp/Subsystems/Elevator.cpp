#include "Subsystems/Elevator.h"
#include "Commands/Looped/RunElevator.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  m_elevator.RestoreFactoryDefaults();
  m_elevator.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_elevator.SetInverted(true);

  m_PID.SetP(elevator_kP);
  m_PID.SetI(elevator_kI);
  m_PID.SetD(elevator_kD);
  m_PID.SetFF(0);
}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new RunElevator);
}

void Elevator::SetSpeed(double speed) {
  if (GetBrake() == false) {
    m_elevator.Set(speed);
  } else {
    m_elevator.Set(0);
  }
}

void Elevator::SetPIDSpeed(double target) {
    m_PID.SetReference((target - kElevatorStartingHeight) / (kElevatorGearRatio * kElevatorPulleyDiameter * pi), rev::ControlType::kPosition);
  if (GetBrake() == true) {
    m_elevator.Set(0);
  }
}

double Elevator::GetHeight() {
  return kElevatorStartingHeight + (m_encoder.GetPosition() * kElevatorGearRatio * kElevatorPulleyDiameter * pi);
}

void Elevator::SetBrake(bool position) {
  m_brake.Set(!position);
}

bool Elevator::GetBrake() {
  return !m_brake.Get();
}