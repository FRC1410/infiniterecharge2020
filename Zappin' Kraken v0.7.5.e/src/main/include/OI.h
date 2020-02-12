#pragma once

#include "Util/Libraries.h"
#include "Util/Controller.h"
#include "RobotMap/IDs.h"

class OI {
  private:
    Controller m_controller;
    frc::Joystick driver_controller{kDriverPort}, operator_controller{kOperatorPort}, test_controller{kTestPort};

    frc::JoystickButton LimelightAlignButton{&driver_controller, kLimelightAlignButton};

    frc::JoystickButton FlipDesiredIntakePositionButton{&operator_controller, kIntakeFlipperButton};
    frc::JoystickButton ShootButton{&operator_controller, kShootButton};
    frc::JoystickButton ActuateControlPanelButton{&operator_controller, kActuateControlPanelButton};
    frc::JoystickButton RotationControlButton{&operator_controller, kRotationControlButton};
    frc::JoystickButton PositionControlPrimaryButton{&operator_controller, kPositionControlPrimaryButton};
    frc::JoystickButton PositionControlSecondaryButton{&operator_controller, kPositionControlSecondaryButton};

    frc::POVButton ElevatorRaiseButton{operator_controller, kElevatorRaisePOVAngle, kPOVNumber};
    frc::POVButton ElevatorLowerButton{operator_controller, kElevatorLowerPOVAngle, kPOVNumber};

    frc::JoystickButton ShooterTest{&driver_controller, 6};
    frc::JoystickButton ShoveTest{&driver_controller, 5};

    frc::JoystickButton LimelightTest{&driver_controller, 6};
    frc::JoystickButton DebouncedLimelightTest{&test_controller, 1};

  public:
    OI();

    double GetDriverAxis(int axis);
    bool GetDriverButton(int button);
    int GetDriverDPad();
    void SetDriverRumble(double speed);

    double GetOperatorAxis(int axis);
    bool GetOperatorButton(int button);
    int GetOperatorDPad();
    void SetOperatorRumble(double speed);

    double GetTestAxis(int axis);
    bool GetTestButton(int button);
    int GetTestDPad();
    void SetTestRumble(double speed);
};