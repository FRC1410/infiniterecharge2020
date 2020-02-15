#include "Commands/Actions/AlertDriver.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

AlertDriver::AlertDriver() {}

void AlertDriver::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void AlertDriver::Execute() {
  Robot::m_oi.SetDriverRumble(kSingleRumbleStrength);
}

bool AlertDriver::IsFinished() {
  return (Robot::m_limelight.GetTarget() == true);
}

void AlertDriver::End() {
  Robot::m_oi.SetDriverRumble(0);
}

void AlertDriver::Interrupted() {
  End();
}