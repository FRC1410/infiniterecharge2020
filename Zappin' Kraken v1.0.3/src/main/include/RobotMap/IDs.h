#pragma once

//Controllers
constexpr int kDriverPort = 0;
constexpr int kOperatorPort = 1;
constexpr int kTestPort = 2;

constexpr int kPOVNumber = 0;

//Drivetrain
constexpr int kDrivetrainFrontLeftMotor = 1;       //Talon FX
constexpr int kDrivetrainFrontRightMotor = 2;      //Talon FX
constexpr int kDrivetrainBackLeftMotor = 3;        //Talon FX
constexpr int kDrivetrainBackRightMotor = 4;       //Talon FX

constexpr int kLeftDriveAxis = 1;                  //Driver Left Stick Y-axis
constexpr int kRightDriveAxis = 5;                 //Driver Right Stick Y-axis

constexpr int kInvertDrivingButton = 5;            //Driver Left Bumper

//Intake
constexpr int kIntakeMotor = 10;                   //Victor SPX

constexpr int kIntakeAxis = 3;                     //Operator Right Trigger
constexpr int kOuttakeAxis = 2;                    //Operator Left Trigger

//Intake Flipper
constexpr int kIntakeFlipperMotor = 11;            //Spark MAX

constexpr int kIntakeFlipButton = 6;               //Operator Right Bumper
constexpr int kIntakeFlipperMidButton = 4;         //Operator Y

//Storage
constexpr int kHorizontalStorageLeftMotor = 20;    //Talon SRX
constexpr int kHorizontalStorageRightMotor = 21;   //Talon SRX
constexpr int kVerticalStorageFrontMotor = 22;     //Talon SRX
constexpr int kVerticalStorageBackMotor = 23;      //Talon SRX

constexpr int kPhotoelectricPort = 0;              //Digital Input

constexpr int kStorageOuttakeButton = 5;           //Operator Left Bumper

constexpr int kStorageManualControlButton = 7;     //Operator Back

//Shooter
constexpr int kShooterMotor = 30;                  //Talon FX

constexpr int kRunShooterButton = 1;               //A
constexpr int kIncrementRPMPOVAngle = 0;           //Operator D-pad Up
constexpr int kDecrementRPMPOVAngle = 180;         //Operator D-pad Down
constexpr int kIncrementAngleOffsetPOVAngle = 90;  //Operator D-pad Right
constexpr int kDecrementAngleOffsetPOVAngle = 270; //Operator D-pad Left

//Elevator
constexpr int kElevatorMotor = 40;                 //Spark MAX

constexpr int kElevatorSolenoid = 6;               //PCM

constexpr int kElevatorAxis = 1;                   //Operator Left Stick Y-Axis
constexpr int kElevatorRaiseButton = 3;            //Operator X

//Slider
constexpr int kSliderMotor = 41;                   //Talon SRX

constexpr int kSliderAxis = 4;                     //Operator Right Stick X-Axis

//Control Panel
constexpr int kControlPanelMotor = 50;             //Talon SRX

constexpr int kRotationControlButton = 2;          //Operator B
constexpr int kPositionControlButton = 8;          //Operator Start

//Limelight
constexpr int kLimelightShootButton = 6;           //Driver Right Bumper

//Feedback
constexpr int kLEDController = 0;                  //PWM
constexpr int kPressureSensor = 0;                 //Analog Input