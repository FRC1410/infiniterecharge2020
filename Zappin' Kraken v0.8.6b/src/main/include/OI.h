#pragma once

#include "Util/Libraries.h"
#include "Util/Controller.h"
#include "RobotMap/IDs.h"

class OI {
  private:
    Controller m_controller;
    frc::Joystick driver_controller{kDriverPort}, operator_controller{kOperatorPort}, test_controller{kTestPort};

    frc::JoystickButton LimelightShootButton{&driver_controller, kLimelightShootButton};

    frc::JoystickButton IntakeMidPositionButton{&operator_controller, kIntakeLoadingStationButton};
    frc::JoystickButton RunShooterButton{&operator_controller, kRunShooterButton};

    frc::POVButton ElevatorRaiseButton{operator_controller, kElevatorRaiseButton, kPOVNumber};
    frc::JoystickButton ActuateElevatorBrakeButton{&operator_controller, kActuateElevatorBrakeButton};

    frc::POVButton RotationControlButton{operator_controller, kRotationControlPOVAngle};
    frc::POVButton PositionControlPrimaryButton{operator_controller, kPositionControlPrimaryPOVAngle};
    frc::POVButton PositionControlSecondaryButton{operator_controller, kPositionControlSecondaryPOVAngle};
    frc::POVButton PositionControlTertiaryButton{operator_controller, kPositionControlTertiaryPOVAngle};

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