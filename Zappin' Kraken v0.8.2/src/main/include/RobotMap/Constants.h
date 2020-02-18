#pragma once

constexpr double pi = 3.141592653589793;
constexpr double kDoubleSize = 8;

constexpr double kFalconTicksPerRevolution = 2048;
constexpr double kFalconTicksToRPM = 600 / kFalconTicksPerRevolution;

//Controllers
constexpr double kDriverJoystickDeadzone = 0.1;   //Joystick Deadzone
constexpr double kDriverTriggerThreshold = 0.1;   //Minimum Trigger Value

constexpr double kOperatorJoystickDeadzone = 0.2; //Joystick Deadzone
constexpr double kOperatorTriggerThreshold = 0.2; //Minimum Trigger Value

constexpr double kTestJoystickDeadzone = 0.1;     //Joystick Deadzone
constexpr double kTestTriggerThreshold = 0.2;     //Minimum Trigger Value

constexpr double kSingleRumbleStrength = 1;
constexpr double kSingleRumbleTime = 0.254;       //Seconds

//Drivetrain
constexpr double kDrivetrainGearRatio = (11.0/62) * (24.0/54) * 1.057;
constexpr double kDrivetrainWheelDiameter = 6;    //Inches

//Intake Flipper
constexpr double kIntakeFlipperStartingAngle = -9; //Degrees to vertical
constexpr double kIntakeFlipperGearRatio = (1.0/5) * (1.0/5);

constexpr double kIntakeSpringXOffset = 0;        //Inches behind rotation point
constexpr double kIntakeSpringYOffset = 0;        //Inches above rotation point
constexpr double kIntakeSpringDistanceOffset = 0; //Inches along intake

//Shooter
constexpr int kShooterPrimaryPID = 0;
constexpr int kShooterAuxillaryPID = 1;

//Elevator
constexpr double kElevatorStartingHeight = 38;    //Inches

constexpr double kElevatorGearRatio = 1.0/20;
constexpr double kElevatorPulleyDiameter = 1.273; //Pitch Diameter of Sprocket, Inches

//Control Panel
constexpr int kControlPanelPrimaryOffset = 2;     //Red field, yellow robot is offset of 1
constexpr int kControlPanelSecondaryOffset = 1;   //Red field, yellow robot is offset of 1
constexpr int kRotationControlEighthRevolutions = 25;

//Limelight
constexpr double kLimelightVerticalFOV = 49.7 * pi/180;
constexpr int kTargetHeight = 17;                 //Height of Vision Target, Inches

//Auto
constexpr double kTimedDriveDefaultSpeed = 0.5;
constexpr double kTimedDriveDefaultTime = 2;