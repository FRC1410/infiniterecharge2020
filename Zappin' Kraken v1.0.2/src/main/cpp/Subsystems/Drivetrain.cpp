#include "Subsystems/Drivetrain.h"
#include "Commands/Looped/Drive.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
	m_left_front.ConfigFactoryDefault();
	m_right_front.ConfigFactoryDefault();
	m_left_back.ConfigFactoryDefault();
	m_right_back.ConfigFactoryDefault();

	m_left_front.SetNeutralMode(NeutralMode::Brake);
	m_right_front.SetNeutralMode(NeutralMode::Brake);
	m_left_back.SetNeutralMode(NeutralMode::Brake);
	m_right_back.SetNeutralMode(NeutralMode::Brake);

  m_left_front.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_right_front.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_left_back.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);
  m_right_back.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, kPrimaryPID, kPIDTimeout);

	m_left_front.SetInverted(true);
	m_right_front.SetInverted(true);
	m_left_back.SetInverted(true);
	m_right_back.SetInverted(true);
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

void Drivetrain::SetCurvedTeleOpSpeed(double left, double right) {
	if (left == 0) {
		left_speed = 0;
	} else if (abs(left) < kDrivetrainTeleOpFrictionDeadband) {
		left_speed = (abs(left) / left) * kDrivetrainTeleOpFrictionAmount * sqrt(abs(left) / kDrivetrainTeleOpFrictionDeadband);
	} else {
	  left_speed = (abs(left) / left) * ((abs(left) + kDrivetrainTeleOpFrictionAmount * (1 - abs(left)) - kDrivetrainTeleOpFrictionDeadband) / (1 - kDrivetrainTeleOpFrictionDeadband));
  }

	if (right == 0) {
		right_speed = 0;
	} else if (abs(right) < kDrivetrainTeleOpFrictionDeadband) {
		right_speed = (abs(right) / right) * kDrivetrainTeleOpFrictionAmount * sqrt(abs(right) / kDrivetrainTeleOpFrictionDeadband);
	} else {
	  right_speed = (abs(right) / right) * ((abs(right) + kDrivetrainTeleOpFrictionAmount * (1 - abs(right)) - kDrivetrainTeleOpFrictionDeadband) / (1 - kDrivetrainTeleOpFrictionDeadband));
  }

	SetRawSpeed(left_speed, right_speed);

}

void Drivetrain::SetCurvedTeleOpArcadeSpeed(double speed, double rotational_speed) {
	SetCurvedTeleOpSpeed(speed + rotational_speed, speed - rotational_speed);
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
  left_distance = (m_left_front.GetSelectedSensorPosition() + m_left_back.GetSelectedSensorPosition()) / 2;
  right_distance = -(m_right_front.GetSelectedSensorPosition() + m_right_back.GetSelectedSensorPosition()) / 2;
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
	if (GetAngle() - previous_angle == 0) {
		linear_displacement = GetDistance() - previous_distance;
	} else {
  	linear_displacement = 2 * (GetDistance() - previous_distance) * abs(sin((GetAngle() - previous_angle) * pi/360) / ((GetAngle() - previous_angle) * pi/180));
	}
  x_position += sin((GetAngle() + previous_angle) * pi/360) * linear_displacement;
  z_position += cos((GetAngle() + previous_angle) * pi/360) * linear_displacement;
	previous_distance = GetDistance();
	previous_angle = GetAngle();
}

double Drivetrain::GetX() {
  return x_position;
}

double Drivetrain::GetZ() {
  return z_position;
}