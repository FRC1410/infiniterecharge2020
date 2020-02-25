#include "Subsystems/Drivetrain.h"
#include "Commands/Looped/Drive.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
	m_left_1.ConfigFactoryDefault();
	m_right_1.ConfigFactoryDefault();
	m_left_2.ConfigFactoryDefault();
	m_right_2.ConfigFactoryDefault();

	m_left_1.SetNeutralMode(NeutralMode::Brake);
	m_right_1.SetNeutralMode(NeutralMode::Brake);
	m_left_2.SetNeutralMode(NeutralMode::Brake);
	m_right_2.SetNeutralMode(NeutralMode::Brake);

  m_left_1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_right_1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_left_2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_right_2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);

	m_left_1.SetInverted(true);
	m_right_1.SetInverted(true);
	m_left_2.SetInverted(true);
	m_right_2.SetInverted(true);
}

void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new Drive);
}

void Drivetrain::SetRawSpeed(double left, double right) {
	if (abs(left) > 1) {
		left_speed = abs(left) / left;
	} else {
		left_speed = left;
	}

	if (abs(right) > 1) {
		right_speed = abs(right) / right;
	} else {
		right_speed = right;
	}

	m_drive.TankDrive(kLeftDriveSpeedAdjustment * left_speed, kRightDriveSpeedAdjustment * right_speed);
}

void Drivetrain::SetCurvedSpeed(double left, double right) {
	if (left == 0) {
		left_speed = 0;
	} else if (abs(left) < kDrivetrainFrictionDeadband) {
		left_speed = (abs(left) / left) * kDrivetrainFrictionAmount * sqrt(abs(left) / kDrivetrainFrictionDeadband);
	} else {
	  left_speed = (abs(left) / left) * ((abs(left) + kDrivetrainFrictionAmount * (1 - abs(left)) - kDrivetrainFrictionDeadband) / (1 - kDrivetrainFrictionDeadband));
  }

	if (right == 0) {
		right_speed = 0;
	} else if (abs(right) < kDrivetrainFrictionDeadband) {
		right_speed = (abs(right) / right) * kDrivetrainFrictionAmount * sqrt(abs(right) / kDrivetrainFrictionDeadband);
	} else {
	  right_speed = (abs(right) / right) * ((abs(right) + kDrivetrainFrictionAmount * (1 - abs(right)) - kDrivetrainFrictionDeadband) / (1 - kDrivetrainFrictionDeadband));
  }

	SetRawSpeed(left_speed, right_speed);
}

double Drivetrain::GetCurvedSpeed(double value) {
	if (value == 0) {
		return 0;
	} else if (abs(value) < kDrivetrainFrictionAmount) {
		return (abs(value) * value * kDrivetrainFrictionDeadband) / pow(kDrivetrainFrictionAmount, 2);
	} else {
		return (abs(value) / value) * ((abs(value) + kDrivetrainFrictionDeadband * (1 - abs(value)) - kDrivetrainFrictionAmount) / (1 - kDrivetrainFrictionAmount));
	}
}

double Drivetrain::GetLinearCurvedSpeed() {
	return (GetCurvedSpeed(left_speed) + GetCurvedSpeed(right_speed)) / 2;
}

double Drivetrain::GetRotationalCurvedSpeed() {
	return (GetCurvedSpeed(left_speed) - GetCurvedSpeed(right_speed)) / 2;
}

void Drivetrain::SetCurvedArcadeSpeed(double speed, double rotational_speed) {
	SetCurvedSpeed(speed + rotational_speed, speed - rotational_speed);
}

double Drivetrain::ApplyAcceleration(double current_speed, double target_speed, double acceleration_time, double time_difference) {
  if (abs(target_speed - current_speed) < (time_difference / acceleration_time)) {
    return target_speed;
  } else {
    return current_speed + (time_difference / acceleration_time) * (abs(target_speed - current_speed) / (target_speed - current_speed));
  }
}

void Drivetrain::CurvedArcadeAccelerate(double speed, double rotational_speed, double time_difference) {
	speed = ApplyAcceleration(GetLinearCurvedSpeed(), speed, kDrivetrainLinearAccelerationTime, time_difference);
	rotational_speed = ApplyAcceleration(GetRotationalCurvedSpeed(), rotational_speed, kDrivetrainRotationalAccelerationTime, time_difference);
	SetCurvedArcadeSpeed(speed, rotational_speed);
}

void Drivetrain::ResetEncoders() {
	starting_distance += GetDistance();
  previous_distance = 0;
}

double Drivetrain::GetDistance() {
  left_distance = (m_left_1.GetSelectedSensorPosition() + m_left_2.GetSelectedSensorPosition()) / 2;
  right_distance = -(m_right_1.GetSelectedSensorPosition() + m_right_2.GetSelectedSensorPosition()) / 2;
  return (((kDrivetrainWheelDiameter * pi * kDrivetrainGearRatio) / kFalconTicksPerRevolution) * ((left_distance + right_distance) / 2)) - starting_distance;
}

void Drivetrain::ResetGyro(double angle_input) {
  starting_angle = angle_input;
  previous_angle = angle_input;
  NavX.Reset();
}

double Drivetrain::GetAngle() {
  return NavX.GetAngle() + starting_angle;
}

void Drivetrain::SetXZ(double x_input, double z_input) {
  x_position = x_input;
  z_position = z_input;
}

void Drivetrain::IncrementXZ() {
	frc::SmartDashboard::PutNumber("ting ting", 3310);
	if (GetAngle() - previous_angle == 0) {
		linear_displacement = GetDistance() - previous_distance;
	} else {
  	linear_displacement = 2 * (GetDistance() - previous_distance) * abs(sin((GetAngle() - previous_angle) * pi/360.0) / ((GetAngle() - previous_angle) * pi/180.0));
	}
		//linear_displacement = GetDistance() - previous_distance;
	frc::SmartDashboard::PutNumber("previous_distance", linear_displacement);
  x_position += sin((GetAngle() + previous_angle) * pi/360.0) * linear_displacement;
  z_position += cos((GetAngle() + previous_angle) * pi/360.0) * linear_displacement;
	previous_distance = GetDistance();
	previous_angle = GetAngle();
}

double Drivetrain::GetX() {
  return x_position;
}

double Drivetrain::GetZ() {
  return z_position;
}