#include "Auto/Actions/ResetPosition.h"
#include "Robot.h"

ResetPosition::ResetPosition(double x_input, double z_input, double angle_input) {
  x = x_input;
  z = z_input;
  angle = angle_input;
}

void ResetPosition::Initialize() {
  Robot::m_drivetrain.ResetEncoders();
  Robot::m_drivetrain.ResetGyro(angle);
  Robot::m_drivetrain.SetXZ(x, z);
}

void ResetPosition::Execute() {}

bool ResetPosition::IsFinished() {
  return true;
}

void ResetPosition::End() {}

void ResetPosition::Interrupted() {}