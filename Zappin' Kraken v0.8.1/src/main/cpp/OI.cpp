#include "OI.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"

#include "Commands/Groups/LimelightAlign.h"

#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Commands/Actions/Shoot.h"
#include "Commands/Groups/RunShooter.h"

#include "Commands/Actions/ActuateElevatorLock.h"

#include "Commands/Actions/ActuateControlPanel.h"
#include "Commands/Actions/RotationControl.h"
#include "Commands/Actions/PositionControl.h"

OI::OI() {  
  LimelightAlignButton.WhileHeld(new LimelightAlign);

  FlipDesiredIntakePositionButton.WhenPressed(new FlipDesiredIntakePosition);
  ShootButton.WhileHeld(new Shoot);
  RunShooterButton.ToggleWhenPressed(new RunShooter);

  ActuateElevatorLockButton.WhenPressed(new ActuateElevatorLock);

  ActuateControlPanelButton.WhenPressed(new ActuateControlPanel);
  RotationControlButton.ToggleWhenPressed(new RotationControl);
  PositionControlPrimaryButton.ToggleWhenPressed(new PositionControl(kControlPanelPrimaryOffset));
  PositionControlSecondaryButton.ToggleWhenPressed(new PositionControl(kControlPanelSecondaryOffset));

}

//Driver Controller
double OI::GetDriverAxis(int axis) {
  return m_controller.ApplyDeadzone(kDriverPort, axis, kDriverJoystickDeadzone, kDriverTriggerThreshold);
}

bool OI::GetDriverButton(int button) {
  return driver_controller.GetRawButton(button);
}

int OI::GetDriverDPad() {
  return driver_controller.GetPOV();
}

void OI::SetDriverRumble(double speed) {
  driver_controller.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, speed);
  driver_controller.SetRumble(frc::GenericHID::RumbleType::kRightRumble, speed);
}

//Operator Controller
double OI::GetOperatorAxis(int axis) {
  return m_controller.ApplyDeadzone(kOperatorPort, axis, kOperatorJoystickDeadzone, kOperatorTriggerThreshold);
}

bool OI::GetOperatorButton(int button) {
  return operator_controller.GetRawButton(button);
}

int OI::GetOperatorDPad() {
  return operator_controller.GetPOV();
}

void OI::SetOperatorRumble(double speed) {
  operator_controller.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, speed);
  operator_controller.SetRumble(frc::GenericHID::RumbleType::kRightRumble, speed);
}

//Test Controller
double OI::GetTestAxis(int axis) {
  return m_controller.ApplyDeadzone(kTestPort, axis, kTestJoystickDeadzone, kTestTriggerThreshold);
}

bool OI::GetTestButton(int button) {
  return test_controller.GetRawButton(button);
}

int OI::GetTestDPad() {
  return test_controller.GetPOV();
}

void OI::SetTestRumble(double speed) {
  test_controller.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, speed);
  test_controller.SetRumble(frc::GenericHID::RumbleType::kRightRumble, speed);
}