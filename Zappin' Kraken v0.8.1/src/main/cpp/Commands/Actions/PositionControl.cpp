#include "Commands/Actions/PositionControl.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

PositionControl::PositionControl(int offset_input) {
  Requires(&Robot::m_control_panel);
  offset = offset_input;
}

void PositionControl::Initialize() {
  m_rumble_timer.Reset();
  m_rumble_timer.Stop();

  m_delay_timer.Reset();
  m_delay_timer.Stop();

  target = Robot::m_control_panel.GetFMSData(offset);
  if (target < 0 || target == Robot::m_control_panel.GetColor()) {
    Robot::m_oi.SetOperatorRumble(kSingleRumbleStrength);
    m_rumble_timer.Start();
  }  
}

void PositionControl::Execute() {
  if (target >= 0) {
    current = Robot::m_control_panel.GetColor();
    if ((target - current + 4) % 4 == 3) {
      Robot::m_control_panel.SetSpeed(-kPositionControlSpeed);
    } else {
      Robot::m_control_panel.SetSpeed(kPositionControlSpeed);
    }
  }

  if (target == current) {
    m_delay_timer.Start();
  }
}

bool PositionControl::IsFinished() {
  return (m_delay_timer.Get() > kPositionControlDelay || m_rumble_timer.Get() > kSingleRumbleTime);
}

void PositionControl::End() {
  Robot::m_control_panel.SetSpeed(0);
  Robot::m_oi.SetOperatorRumble(0);
}

void PositionControl::Interrupted() {
  End();
}