#include "Subsystems/ControlPanel.h"
#include "RobotMap/Tuning.h"

ControlPanel::ControlPanel() : Subsystem("ExampleSubsystem") {
  m_wheel.ConfigFactoryDefault();
  m_wheel.SetNeutralMode(NeutralMode::Brake);
  m_wheel.SetInverted(false);

  m_color_matcher.AddColorMatch(kRedTarget);
  m_color_matcher.AddColorMatch(kGreenTarget);
  m_color_matcher.AddColorMatch(kBlueTarget);
  m_color_matcher.AddColorMatch(kYellowTarget);
}

void ControlPanel::InitDefaultCommand() {}

void ControlPanel::SetSpeed(double speed) {
  m_wheel.Set(speed);
}

int ControlPanel::GetColor() {
  matched_color = m_color_matcher.MatchClosestColor(m_color_sensor.GetColor(), confidence);

  if (matched_color == kRedTarget) {
    color = 0;
  } else if (matched_color == kGreenTarget) {
    color = 1;
  } else if (matched_color == kBlueTarget) {
    color = 2;
  } else {
    color = 3;
  }

  return color;
}

int ControlPanel::GetFMSData(int offset) {
  game_data = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  if (game_data.length() > 0) {
    switch (game_data[0]) {
      case 'R':
        return (4 - offset) % 4;
        break;
      case 'G':
        return (5 - offset) % 4;
        break;
      case 'B':
        return (6 - offset) % 4;
        break;
      case 'Y':
        return (7 - offset) % 4;
        break;
      default:
        return -1;
    }
  } else {
    return -1;
  }
}