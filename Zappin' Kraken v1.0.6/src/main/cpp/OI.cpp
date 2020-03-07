#include "OI.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

#include "Commands/Groups/ManualLimelightShoot.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"
#include "Commands/Actions/ShooterPID.h"

#include "Commands/Actions/RaiseElevator.h"

#include "Commands/Actions/RotationControl.h"
#include "Commands/Actions/PositionControl.h"

OI::OI() {  
  LimelightShootButton.WhileHeld(new ManualLimelightShoot);

  FlipIntakePositionButton.WhenPressed(new SetDesiredIntakePosition(kIntakeFlipperToggle));
  IntakeMidPositionButton.WhenPressed(new SetDesiredIntakePosition(kIntakeFlipperMid));
  IntakeMidPositionButton.WhenReleased(new SetDesiredIntakePosition(kIntakeFlipperUp));
  RunShooterButton.ToggleWhenPressed(new ShooterPID);

  RaiseElevatorButton.ToggleWhenPressed(new RaiseElevator(kElevatorTarget));
  RotationControlButton.ToggleWhenPressed(new RotationControl);
  PositionControlButton.ToggleWhenPressed(new PositionControl(kControlPanelOffset));
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