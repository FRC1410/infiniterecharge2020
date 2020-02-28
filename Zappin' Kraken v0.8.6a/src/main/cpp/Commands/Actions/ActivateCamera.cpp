#include "Commands/Actions/ActivateCamera.h"
#include "Robot.h"

ActivateCamera::ActivateCamera() {
  run = true;
}

ActivateCamera::ActivateCamera(bool run_input) {
  run = run_input;
}

void ActivateCamera::Initialize() {
  if (run == false) {
    End();
  }
}

void ActivateCamera::Execute() {
  Robot::m_limelight.TurnOnLights();
}

bool ActivateCamera::IsFinished() {
  return false;
}

void ActivateCamera::End() {
  Robot::m_limelight.TurnOffLights();
}

void ActivateCamera::Interrupted() {
  End();
}