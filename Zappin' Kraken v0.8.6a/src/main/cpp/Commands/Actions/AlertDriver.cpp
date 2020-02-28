#include "Commands/Actions/AlertDriver.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

AlertDriver::AlertDriver() {
  run = true;
}

AlertDriver::AlertDriver(bool run_input) {
  run = run_input;
}

void AlertDriver::Initialize() {
  if (run == false) {
    End();
  }
}

void AlertDriver::Execute() {
  if (Robot::m_limelight.GetTarget() == false) {
    Robot::m_oi.SetDriverRumble(kSingleRumbleStrength);
  } else {
    Robot::m_oi.SetDriverRumble(0);
  }
}

bool AlertDriver::IsFinished() {
  return false;
}

void AlertDriver::End() {
  Robot::m_oi.SetDriverRumble(0);
}

void AlertDriver::Interrupted() {
  End();
}