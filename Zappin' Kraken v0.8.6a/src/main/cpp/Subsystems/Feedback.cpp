#include "Subsystems/Feedback.h"

Feedback::Feedback() : Subsystem("ExampleSubsystem") {}

void Feedback::InitDefaultCommand() {}

double Feedback::GetPressure() {
  return (50 * m_pressure.GetVoltage()) - 25; 
}