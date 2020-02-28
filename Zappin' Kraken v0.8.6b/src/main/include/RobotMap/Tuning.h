#pragma once

#include <frc/Util/Color.h>

//Drivetrain
constexpr double kLeftDriveSpeedAdjustment = 1;
constexpr double kRightDriveSpeedAdjustment = 1;

constexpr double kDrivetrainFrictionDeadband = 0.05;
constexpr double kDrivetrainFrictionAmount = 0.254;

constexpr double kDrivetrainTeleOpFrictionDeadband = 0.2;
constexpr double kDrivetrainTeleOpFrictionAmount = 1.0/3;

constexpr double kDrivetrainLinearAccelerationTime = 1;         //Seconds
constexpr double kDrivetrainRotationalAccelerationTime = 1;     //Seconds

constexpr double drivetrain_distance_kP = 0.02;
constexpr double drivetrain_distance_kI = 0;
constexpr double drivetrain_distance_kD = 0;

constexpr double drivetrain_angle_kP = 0.01;
constexpr double drivetrain_angle_kI = 0;
constexpr double drivetrain_angle_kD = 0.001;

//Intake
constexpr double kIntakeSpeedAdjustment = 1;

//Intake Flipper
constexpr double kIntakeUpTarget = -45;                         //Degrees
constexpr double kIntakeMidTarget = 40;                         //Degrees
constexpr double kIntakeDownTarget = 100;                       //Degrees

constexpr double kIntakeUpThreshold = -6;                       //Degrees
constexpr double kIntakeDownThreshold = 100;                    //Degrees

constexpr double kIntakeFlipperDownPowerCap = 0.2;
constexpr double kIntakeFlipperUpPowerCap = -0.3;

constexpr double intake_flipper_kP = 0.027;
constexpr double intake_flipper_kI = 0;
constexpr double intake_flipper_kD = 0;

//Storage
constexpr double kHorizontalStorageSpeed = 1;
constexpr double kVerticalStorageSpeed = 1;

constexpr double kHorizontalStorageFeedShooterSpeed = 1;
constexpr double kVerticalStorageFeedShooterSpeed = 1;

constexpr double kVerticalFeedShooterTimeout = 2;               //Seconds
constexpr double kFeedShooterTimeout = 3.3;                     //Seconds

constexpr double kStoragePhotoelectricDelay = 0.2;              //Seconds

//Shooter
constexpr double kAccelerationTime = 0.254;                     //Seconds

constexpr double kShooterDistanceProfiles[] = {126, 180, 254, 408};
constexpr double kShooterRPMProfiles[] = {3250, 3250, 3600, 4520}; //4465
constexpr double kShooterAngleOffsets[] = {1, 1, 2.2, 1};

constexpr double kShooterRPMIncrement = 25;
constexpr double kShooterAngleIncrement = 0.1;

constexpr double shooter_kP = 0.3;
constexpr double shooter_kI = 0;
constexpr double shooter_kD = 0;
constexpr double shooter_kF = 0.0468;

//Elevator
constexpr double kElevatorTarget = 62.4;                        //Inches to bottom of slider
constexpr double kElevatorFinishedThreshold = 2;                //Inches

constexpr double elevator_kP = 0.01;
constexpr double elevator_kI = 0;
constexpr double elevator_kD = 0;

//Control Panel
constexpr double kRotationControlSpeed = 1;
constexpr double kPositionControlSpeed = 1;
constexpr double kPositionControlDelay = 0.03;                  //Seconds

constexpr frc::Color kRedTarget = frc::Color(0.42, 0.4, 0.18);
constexpr frc::Color kYellowTarget = frc::Color(0.32, 0.58, 0.15);
constexpr frc::Color kBlueTarget = frc::Color(0.18, 0.46, 0.36);
constexpr frc::Color kGreenTarget = frc::Color(0.21, 0.6, 0.26);

//Limelight
constexpr double kLimelightAngleFinishedThreshold = 1;          //+- degrees
constexpr double kLimelightDistanceFinishedThreshold = 4;       //+- inches
constexpr double kLimelightDistanceFinishedTimeThreshold = 0.5; //+- inches

constexpr double kLimelightAngleTimeout = 1;                    //Seconds
constexpr double kLimelightDistanceTimeout = 3;                 //Seconds

constexpr double kLimelightDistanceMultiplier = 0.95;           //Linear Regression
constexpr double kLimelightDistanceOffset = 0;                  //Linear Regression

constexpr double kLimelightLinearCap = 0.4;

constexpr double limelight_distance_kP = 0.02;
constexpr double limelight_distance_kI = 0;
constexpr double limelight_distance_kD = 0;

constexpr double limelight_angle_kP = 0.01;
constexpr double limelight_angle_kI = 0;
constexpr double limelight_angle_kD = 0.001;

constexpr double limelight_sqrt_angle_kP = 0.06;
constexpr double limelight_sqrt_angle_kI = 0;
constexpr double limelight_sqrt_angle_kD = 0.005;

constexpr int kSmoothLimelightDistanceIndex = 20;

//Auto
constexpr double x_offset_kP = 0.0254;
constexpr double x_offset_kI = 0;
constexpr double x_offset_kD = 0;

constexpr double kDistanceFinishedThreshold = 4;                //+-Inches
constexpr double kAngleFinishedThreshold = 2;                   //Degrees