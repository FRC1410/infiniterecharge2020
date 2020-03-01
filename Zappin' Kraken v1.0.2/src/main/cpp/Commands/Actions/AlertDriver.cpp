#include "Commands/Actions/AlertDriver.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

AlertDriver::AlertDriver() {}

void AlertDriver::Initialize() {
  Robot::m_feedback.SetAligning(true);
}

void AlertDriver::Execute() {
  if (Robot::m_limelight.GetTarget() == false) {
    Robot::m_oi.SetDriverRumble(kSingleRumbleStrength);
  } else {
    Robot::m_oi.SetDriverRumble(0);
  }
}

bool AlertDriver::IsFinished() {
  return !Robot::m_feedback.GetAligning();
}

void AlertDriver::End() {
  Robot::m_oi.SetDriverRumble(0);
}

void AlertDriver::Interrupted() {
  End();
}