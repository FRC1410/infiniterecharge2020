#include "Commands/Actions/AlertDriver.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

AlertDriver::AlertDriver() {}

void AlertDriver::Initialize() {
  Robot::m_limelight.ForceLightsOn();

  m_timer.Reset();
  m_timer.Start();
}

void AlertDriver::Execute() {
  if (Robot::m_oi.GetDriverButton(kLimelightAlignButton) == true) {
    Robot::m_oi.SetDriverRumble(kSingleRumbleStrength);
  }
}

bool AlertDriver::IsFinished() {
  return true;//(Robot::m_limelight.GetTarget() == true);
}

void AlertDriver::End() {
  Robot::m_oi.SetDriverRumble(0);
}

void AlertDriver::Interrupted() {
  Robot::m_limelight.ForceLightsOn();
  End();
}