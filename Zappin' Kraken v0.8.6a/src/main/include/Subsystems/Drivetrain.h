#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Drivetrain : public frc::Subsystem {
  private:
    WPI_TalonFX m_left_front{kDrivetrainFrontLeftMotor}, m_right_front{kDrivetrainFrontRightMotor}, m_left_back{kDrivetrainBackLeftMotor}, m_right_back{kDrivetrainBackRightMotor};
    frc::SpeedControllerGroup m_left{m_left_front, m_left_back}, m_right{m_right_front, m_right_back};
    frc::DifferentialDrive m_drive{m_left, m_right};

    AHRS NavX{SPI::Port::kMXP};

    double left_speed, right_speed;

    double left_distance, right_distance, starting_distance, previous_distance;
    double starting_angle, previous_angle;

    double x_position, z_position, linear_displacement;

  public:
    Drivetrain();
    void InitDefaultCommand() override;

    void SetRawSpeed(double left, double right);
    void SetCurvedSpeed(double left, double right);
    double GetCurvedSpeed(double value);
    double GetLinearCurvedSpeed();
    double GetRotationalCurvedSpeed();

    void SetCurvedArcadeSpeed(double speed, double rotational_speed);
    void SetCurvedTeleOpSpeed(double left, double right);
    void SetCurvedTeleOpArcadeSpeed(double speed, double rotational_speed);

    double ApplyAcceleration(double current_speed, double target_speed, double acceleration_time, double time_difference);
    void CurvedArcadeAccelerate(double speed, double rotational_speed, double time_difference);

    void ResetEncoders();
    double GetDistance();
    void ResetGyro(double angle_input);
    double GetAngle();

    void SetXZ(double input_x, double input_z);
    void IncrementXZ();
    double GetX();
    double GetZ();
};