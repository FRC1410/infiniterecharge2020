#include "Commands/Actions/ActuateControlPanel.h"
#include "Robot.h"

ActuateControlPanel::ActuateControlPanel() {}

void ActuateControlPanel::Initialize() {
  if (Robot::m_control_panel.GetPosition() == false) {
    Robot::m_control_panel.Raise();
  } else {
    Robot::m_control_panel.Lower();
  }
}

void ActuateControlPanel::Execute() {}

bool ActuateControlPanel::IsFinished() {
  return true;
}

void ActuateControlPanel::End() {}

void ActuateControlPanel::Interrupted() {}