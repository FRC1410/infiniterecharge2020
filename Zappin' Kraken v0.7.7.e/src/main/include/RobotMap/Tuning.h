#pragma once

#include <frc/Util/Color.h>

//Drivetrain
constexpr double kLeftDriveSpeedAdjustment = 1;
constexpr double kRightDriveSpeedAdjustment = 1;

constexpr double kDrivetrainFrictionDeadband = 0.1;
constexpr double kDrivetrainFrictionAmount = 0.3;

constexpr double kDrivetrainLinearAccelerationTime = 1;     //Seconds
constexpr double kDrivetrainRotationalAccelerationTime = 1; //Seconds

constexpr double drivetrain_distance_kP = 0;
constexpr double drivetrain_distance_kI = 0;
constexpr double drivetrain_distance_kD = 0;

constexpr double drivetrain_angle_kP = 0;
constexpr double drivetrain_angle_kI = 0;
constexpr double drivetrain_angle_kD = 0;

//Intake
constexpr double kIntakeSpeedAdjustment = 1;

//Intake Flipper
constexpr double kNEOTicksToDegrees = (double) 360 / 4096;

constexpr double kIntakeFlipperDownSpeed = 0.07;
constexpr double kIntakeFlipperUpSpeed = -0.15;

constexpr double kIntakeFlipperDownPowerCap = 0.2;
constexpr double kIntakeFlipperUpPowerCap = -0.2;

constexpr double kIntakeDownTarget = 125;                   //Degrees
constexpr double kIntakeUpTarget = -10;                     //Degrees

constexpr double kIntakeDownThreshold = 115;                //Degrees
constexpr double kIntakeUpThreshold = 0;                    //Degrees

constexpr double intake_flipper_kP = 0;
constexpr double intake_flipper_kI = 0;
constexpr double intake_flipper_kD = 0;
constexpr double kIntakeFlipperGravityConstant = 0;
constexpr double kIntakeFlipperSpringConstant = 0;

//Storage
constexpr double kStorageHorizontalSpeed = 0.3;
constexpr double kStorageVerticalSpeed = 0.6;

constexpr double kStorageFeedShooterHorizontalSpeed = 0.5;
constexpr double kStorageFeedShooterVerticalSpeed = 1;

//Shooter
constexpr double kFalconTicksToRPM = (double) 600 / 2048;
constexpr double target_RPM = 4500 / kFalconTicksToRPM;

constexpr double kAccelerationTime = 1;                     //Seconds
constexpr double kBallCountResetTime = 2;                   //Seconds

constexpr double kShooterDistanceProfiles[] = {180, 254, 396};
constexpr double kShooterRPMProfiles[] = {4200, 4000, 4500};

constexpr double shooter_kP = 0.3;
constexpr double shooter_kI = 0;
constexpr double shooter_kD = 0;
constexpr double shooter_kF = 1023 / (6380 / kFalconTicksToRPM);
constexpr int kShooterPIDTimeout = 30;                      //ms

//Control Panel
constexpr double kRotationControlSpeed = 1;
constexpr double kPositionControlSpeed = 1;
constexpr double kPositionControlDelay = 0.03;              //Seconds

constexpr frc::Color kRedTarget = frc::Color(0.42, 0.4, 0.18);
constexpr frc::Color kYellowTarget = frc::Color(0.32, 0.58, 0.15);
constexpr frc::Color kBlueTarget = frc::Color(0.18, 0.46, 0.36);
constexpr frc::Color kGreenTarget = frc::Color(0.21, 0.6, 0.26);

//Limelight
constexpr double kLimelightAngleOffset = 0;                 //Robot angle offset (degrees)
constexpr double kLimelightAngleFinishedThreshold = 4;      //+- degrees

constexpr double kLimelightDistanceModifier = 0.95;

constexpr double limelight_angle_kP = 0.02;
constexpr double limelight_angle_kI = 0;
constexpr double limelight_angle_kD = 0;

constexpr double limelight_distance_kP = 0.01;
constexpr double limelight_distance_kI = 0;
constexpr double limelight_distance_kD = 0;

//Auto
constexpr double x_offset_kP = 0;
constexpr double x_offset_kI = 0;
constexpr double x_offset_kD = 0;

constexpr double kDistanceFinishedThreshold = 4;            //+-Inches
constexpr double kAngleFinishedThreshold = 4;               //Degrees