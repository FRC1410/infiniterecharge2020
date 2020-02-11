#include "Commands/Looped/RunSlider.h"
#include "Robot.h"

RunSlider::RunSlider() {
  Requires(&Robot::m_slider);
}

void RunSlider::Initialize() {}

void RunSlider::Execute() {
  Robot::m_slider.SetSpeed(Robot::m_oi.GetOperatorAxis(kSliderAxis));
}

bool RunSlider::IsFinished() {
  return false;
}

void RunSlider::End() {}

void RunSlider::Interrupted() {}
