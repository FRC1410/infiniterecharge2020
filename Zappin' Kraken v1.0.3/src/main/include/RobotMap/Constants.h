#pragma once

constexpr double pi = 3.141592653589793;
constexpr double kDoubleSize = 8;
constexpr double kAutoLength = 15;                 //Seconds

//Motors
constexpr double kFalconTicksPerRevolution = 2048;
constexpr double kFalconTicksToRPM = 600 / kFalconTicksPerRevolution;

constexpr int kPrimaryPID = 0;
constexpr int kAuxillaryPID = 1;
constexpr int kPIDTimeout = 30;                    //ms

//Controllers
constexpr double kDriverJoystickDeadzone = 0.1;    //Joystick Deadzone
constexpr double kDriverTriggerThreshold = 0.2;    //Minimum Trigger Value

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

constexpr int kIntakeFlipperUp = 0;                //Profiles
constexpr int kIntakeFlipperMid = 1;               //Profiles
constexpr int kIntakeFlipperDown = 2;              //Profiles
constexpr int kIntakeFlipperToggle = 3;            //Profiles
constexpr int kIntakeFlipperMidToggle = 4;         //Profiles

//Shooter
constexpr double kShooterRPMIncrement = 25;
constexpr double kShooterAngleOffsetIncrement = 0.1;

//Elevator
constexpr double kElevatorStartingHeight = 37;     //Inches to bottom of slider

constexpr double kElevatorGearRatio = 1.0/20;
constexpr double kElevatorPulleyDiameter = 1.273;  //Pitch Diameter of Sprocket, Inches

//Control Panel
constexpr int kRotationControlEighthRevolutions = 25;
constexpr int kControlPanelOffset = 2;             //Red field, yellow robot is offset of 1

//Limelight
constexpr double kLimelightVerticalFOV = 49.7 * pi/180;
constexpr double kLimelightVerticalResolution = 720;
constexpr int kTargetHeight = 17;                  //Height of Vision Target, Inches

//Auto
constexpr int kShootDelay1 = 1;
constexpr int kShootDelay2 = 2;

//LEDs
constexpr double kWhite = 0.93;
constexpr double kBlue = 0.87;
constexpr double kPurple = 0.91;
constexpr double kBallCountColors[5] = {0.75, 0.69, 0.65, 0.61, 0.57};
constexpr double kShooterDecelerationLEDThreshold = -50;