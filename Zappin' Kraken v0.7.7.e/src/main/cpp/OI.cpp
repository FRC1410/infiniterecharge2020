#include "OI.h"
#include "Robot.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

#include "Commands/Groups/LimelightAlign.h"

#include "Commands/Actions/FlipDesiredIntakePosition.h"
#include "Commands/Actions/Shoot.h"
#include "Commands/Actions/ActuateControlPanel.h"
#include "Commands/Actions/RotationControl.h"
#include "Commands/Actions/PositionControl.h"

#include "Commands/Actions/ShooterPID.h"

#include "Commands/Actions/LimelightAnglePID.h"

#include "Commands/Actions/ToggleElevatorBrake.h"

OI::OI() {  
  //LimelightAlignButton.WhileHeld(new LimelightAlign);

  FlipDesiredIntakePositionButton.WhenPressed(new FlipDesiredIntakePosition);
  ShootButton.WhileHeld(new Shoot);
  ActuateControlPanelButton.WhenPressed(new ActuateControlPanel);
  RotationControlButton.ToggleWhenPressed(new RotationControl);
  PositionControlPrimaryButton.ToggleWhenPressed(new PositionControl(kControlPanelPrimaryOffset));
  PositionControlSecondaryButton.ToggleWhenPressed(new PositionControl(kControlPanelSecondaryOffset));
  
  //ShooterTest.ToggleWhenPressed(new ShooterPID(0));
  ShoveTest.ToggleWhenPressed(new Shoot);

  LimelightTest.ToggleWhenPressed(new LimelightAlign);

  ElevatorBrakeButton.ToggleWhenPressed(new ToggleElevatorBrake);
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