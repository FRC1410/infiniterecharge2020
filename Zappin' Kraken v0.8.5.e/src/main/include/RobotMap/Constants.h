#pragma once

constexpr double pi = 3.141592653589793;
constexpr double kDoubleSize = 8;

//Motors

constexpr double kFalconTicksPerRevolution = 2048;
constexpr double kFalconTicksToRPM = 600 / kFalconTicksPerRevolution;

constexpr int kPrimaryPID = 0;
constexpr int kAuxillaryPID = 0;
constexpr int kPIDTimeout = 30;                    //ms

//Controllers
constexpr double kDriverJoystickDeadzone = 0.1;    //Joystick Deadzone
constexpr double kDriverTriggerThreshold = 0.1;    //Minimum Trigger Value

constexpr double kOperatorJoystickDeadzone = 0.2;  //Joystick Deadzone
constexpr double kOperatorTriggerThreshold = 0.2;  //Minimum Trigger Value

constexpr double kTestJoystickDeadzone = 0.1;      //Joystick Deadzone
constexpr double kTestTriggerThreshold = 0.2;      //Minimum Trigger Value

constexpr double kSingleRumbleStrength = 1;
constexpr double kSingleRumbleTime = 0.254;        //Seconds

//Drivetrain
constexpr double kDrivetrainGearRatio = (11.0/62) * (24.0/54) * 1.057;
constexpr double kDrivetrainWheelDiameter = 6;     //Inches

//Intake Flipper
constexpr double kIntakeFlipperStartingAngle = -9; //Degrees to vertical
constexpr double kIntakeFlipperGearRatio = (1.0/5) * (1.0/5);

constexpr int kIntakeFlipperUp = 0;
constexpr int kIntakeFlipperMid = 1;
constexpr int kIntakeFlipperDown = 2;

//Elevator
constexpr double kElevatorStartingHeight = 37;     //Inches to bottom of slider

constexpr double kElevatorGearRatio = 1.0/20;
constexpr double kElevatorPulleyDiameter = 1.273;  //Pitch Diameter of Sprocket, Inches

//Control Panel
constexpr int kControlPanelPrimaryOffset = 2;      //Red field, yellow robot is offset of 1
constexpr int kControlPanelSecondaryOffset = 1;    //Red field, yellow robot is offset of 1
constexpr int kRotationControlEighthRevolutions = 25;

//Limelight
constexpr double kLimelightVerticalFOV = 49.7 * pi/180;
constexpr int kTargetHeight = 17;                  //Height of Vision Target, Inches

//Auto
constexpr double kTimedDriveDefaultSpeed = 0.5;
constexpr double kTimedDriveDefaultTime = 2;