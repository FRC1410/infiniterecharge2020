#pragma once

#include "Util/Libraries.h"
#include "Util/Controller.h"
#include "RobotMap/IDs.h"

class OI {
  private:
    Controller m_controller;
    frc::Joystick driver_controller{kDriverPort}, operator_controller{kOperatorPort}, test_controller{kTestPort};

    frc::JoystickButton LimelightShootButton{&driver_controller, kLimelightShootButton};

    frc::JoystickButton FlipIntakePositionButton{&operator_controller, kIntakeFlipButton};
    frc::JoystickButton IntakeMidPositionButton{&operator_controller, kIntakeFlipperMidButton};
    frc::JoystickButton RunShooterButton{&operator_controller, kRunShooterButton};

    frc::JoystickButton RaiseElevatorButton{&operator_controller, kElevatorRaiseButton};
    frc::JoystickButton RotationControlButton{&operator_controller, kRotationControlButton};
    frc::JoystickButton PositionControlButton{&operator_controller, kPositionControlButton};

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