#include "Commands/Looped/DisplayFeedback.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

DisplayFeedback::DisplayFeedback() {
  Requires(&Robot::m_feedback);
}

void DisplayFeedback::Initialize() {
  previous_dpad_input = Robot::m_oi.GetOperatorDPad();
  manual_control_was_pressed = Robot::m_oi.GetOperatorButton(kStorageManualControlButton);
  previous_RPM = Robot::m_shooter.GetRPM();
}

void DisplayFeedback::Execute() {
  if (Robot::m_shooter.GetSpeed() > 0) {
    if ((Robot::m_shooter.GetRPM() - previous_RPM) < kShooterDecelerationLEDThreshold) {
      Robot::m_feedback.SetLEDs(kWhite);
    } else {
      Robot::m_feedback.SetLEDs(kBlue);
    }
  } else {
    Robot::m_feedback.SetLEDs(kBallCountColors[Robot::m_storage.GetBallCount()]);
  }
  previous_RPM = Robot::m_shooter.GetRPM();

  if (Robot::m_oi.GetOperatorDPad() != previous_dpad_input) {
    switch (Robot::m_oi.GetOperatorDPad()) {
      case kIncrementRPMPOVAngle:
        Robot::m_limelight.IncrementLastRPMProfile(kShooterRPMIncrement);
        break;
      case kDecrementRPMPOVAngle:
        Robot::m_limelight.IncrementLastRPMProfile(-kShooterRPMIncrement);
        break;
      case kIncrementAngleOffsetPOVAngle:
        Robot::m_limelight.IncrementLastAngleOffset(kShooterAngleOffsetIncrement);
        break;
      case kDecrementAngleOffsetPOVAngle:
        Robot::m_limelight.IncrementLastAngleOffset(-kShooterAngleOffsetIncrement);
        break;
    }
  }
  previous_dpad_input = Robot::m_oi.GetOperatorDPad();

  if ((Robot::m_oi.GetOperatorButton(kStorageManualControlButton) == true) && (manual_control_was_pressed == false)) {
    Robot::m_storage.SetManualControl(!Robot::m_storage.GetManualControl());
  }
  manual_control_was_pressed = Robot::m_oi.GetOperatorButton(kStorageManualControlButton);
}

bool DisplayFeedback::IsFinished() {
  return false;
}

void DisplayFeedback::End() {}

void DisplayFeedback::Interrupted() {}
