#pragma once

//Controllers
constexpr int kDriverPort = 0;
constexpr int kOperatorPort = 1;
constexpr int kTestPort = 2;

constexpr int kPOVNumber = 0;

//Drivetrain
constexpr int kDrivetrainLeftMotor1 = 1;           //Talon FX
constexpr int kDrivetrainRightMotor1 = 2;          //Talon FX
constexpr int kDrivetrainLeftMotor2 = 3;           //Talon FX
constexpr int kDrivetrainRightMotor2 = 4;          //Talon FX

constexpr int kLeftDriveAxis = 1;                  //Driver Left Stick Y-axis
constexpr int kRightDriveAxis = 5;                 //Driver Right Stick Y-axis

constexpr int kInvertDrivingButton = 5;            //Driver Left Bumper

//Intake
constexpr int kIntakeMotor = 10;                   //Victor SPX

constexpr int kIntakeAxis = 3;                     //Operator Right Trigger
constexpr int kOuttakeAxis = 2;                    //Operator Left Trigger

//Intake Flipper
constexpr int kIntakeFlipperMotor = 11;            //Spark MAX

constexpr int kIntakeFlipperButton = 6;            //Operator Right Bumper
constexpr int kIntakeLoadingStationButton = 4;     //Operator Y

//Storage
constexpr int kHorizontalStorageLeftMotor = 20;    //Talon SRX
constexpr int kHorizontalStorageRightMotor = 21;   //Talon SRX
constexpr int kVerticalStorageFrontMotor = 22;     //Talon SRX
constexpr int kVerticalStorageBackMotor = 23;      //Talon SRX

constexpr int kBottomPhotoelectricPort = 0;        //Digital Input
constexpr int kTopPhotoelectricPort = 1;           //Digital Input

constexpr int kStorageInButton = 6;                //Right Bumper
constexpr int kStorageOutButton = 5;               //Left Bumper
constexpr int kManualVerticalButton = 3;           //X Button
constexpr int kManualVerticalOverrideButton = 7;   //Back Button

constexpr int kStorageSolenoidStart = 0;           //PCM
constexpr int kStorageSolenoidEnd = 1;             //PCM

constexpr int kShootButton = 5;                    //Operator Left Bumper

//Shooter
constexpr int kShooterMotor = 30;                  //Talon FX

constexpr int kRunShooterButton = 7;               //Back

//Elevator
constexpr int kElevatorMotor = 40;                 //Spark MAX

constexpr int kElevatorSolenoid = 6;               //PCM

constexpr int kElevatorAxis = 1;                   //Operator Left Stick Y-Axis
constexpr int kElevatorRaisePOVAngle = 0;          //D-pad Up
constexpr int kElevatorLowerPOVAngle = 180;        //D-pad Down

constexpr int kActuateElevatorLockButton = 8;      //Operator Start

//Slider
constexpr int kSliderMotor = 41;                   //Talon SRX

constexpr int kSliderAxis = 4;                     //Operator Right Stick X-Axis

//Control Panel
constexpr int kControlPanelMotor = 50;             //Talon SRX
constexpr int kControlPanelSolenoidStart = 2;      //PCM
constexpr int kControlPanelSolenoidEnd = 3;        //PCM

constexpr int kActuateControlPanelButton = 3;      //Operator X

constexpr int kRotationControlButton = 1;          //Operator A
constexpr int kPositionControlPrimaryButton = 2;   //Operator B
constexpr int kPositionControlSecondaryButton = 4; //Operator Y

//Limelight
constexpr int kLimelightAlignButton = 6;           //Driver Right Bumper

//Feedback
constexpr int kPressureSensor = 0;                 //Analog Input