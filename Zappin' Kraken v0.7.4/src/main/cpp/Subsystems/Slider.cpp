#include "Subsystems/Slider.h"
#include "Commands/Looped/RunSlider.h"

Slider::Slider() : Subsystem("ExampleSubsystem") {
  m_slider.ConfigFactoryDefault();
  m_slider.SetNeutralMode(NeutralMode::Brake);
  m_slider.SetInverted(false);
}

void Slider::InitDefaultCommand() {
  SetDefaultCommand(new RunSlider);
}

void Slider::SetSpeed(double speed) {
  m_slider.Set(speed);
}