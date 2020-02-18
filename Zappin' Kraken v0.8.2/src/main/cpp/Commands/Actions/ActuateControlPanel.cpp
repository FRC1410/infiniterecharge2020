#include "Commands/Actions/ActuateControlPanel.h"
#include "Robot.h"

ActuateControlPanel::ActuateControlPanel() {}

void ActuateControlPanel::Initialize() {
  if (Robot::m_control_panel.GetPosition() == frc::DoubleSolenoid::kForward) {
    Robot::m_control_panel.SetPosition(frc::DoubleSolenoid::kReverse);
  } else {
    Robot::m_control_panel.SetPosition(frc::DoubleSolenoid::kForward);
  }
}

void ActuateControlPanel::Execute() {}

bool ActuateControlPanel::IsFinished() {
  return true;
}

void ActuateControlPanel::End() {}

void ActuateControlPanel::Interrupted() {}