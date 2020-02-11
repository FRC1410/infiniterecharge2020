#include "Commands/Actions/RotationControl.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"
#include "Util/Libraries.h"

RotationControl::RotationControl() {
  Requires(&Robot::m_control_panel);
}

void RotationControl::Initialize() {
  eighth_rotations = 0;
  current_color = Robot::m_control_panel.GetColor();
  Robot::m_control_panel.SetSpeed(kRotationControlSpeed);
}

void RotationControl::Execute() {
  if (Robot::m_control_panel.GetColor() == (current_color + 1) % 4) {
    eighth_rotations++;
  } else if (Robot::m_control_panel.GetColor() == (current_color + 2) % 4) {
    eighth_rotations+=2;
  } else if (Robot::m_control_panel.GetColor() == (current_color + 3) % 4) {
    eighth_rotations--;
  }
  current_color = Robot::m_control_panel.GetColor();
}

bool RotationControl::IsFinished() {
  return (eighth_rotations >= kRotationControlEighthRevolutions);
}

void RotationControl::End() {
  Robot::m_control_panel.SetSpeed(0);
}

void RotationControl::Interrupted() {
  End();
}