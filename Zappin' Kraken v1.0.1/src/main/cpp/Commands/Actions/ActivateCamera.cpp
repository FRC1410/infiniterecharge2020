#include "Commands/Actions/ActivateCamera.h"
#include "Robot.h"

ActivateCamera::ActivateCamera() {}

void ActivateCamera::Initialize() {
  Robot::m_feedback.SetAligning(true);
}

void ActivateCamera::Execute() {
  Robot::m_limelight.TurnOnLights();
}

bool ActivateCamera::IsFinished() {
  return !Robot::m_feedback.GetAligning();
}

void ActivateCamera::End() {
  Robot::m_limelight.TurnOffLights();
}

void ActivateCamera::Interrupted() {
  End();
}