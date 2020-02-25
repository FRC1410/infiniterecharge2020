#pragma once

#include "Util/Libraries.h"

class GreenScreen : public frc::Subsystem {
  public:
    nt::NetworkTableEntry estimated_distance_entry, gyro_angle_entry, battery_voltage_entry, match_time_entry, boost_entry, log_entry;
    nt::NetworkTableEntry auto_chooser_entry, auto_list_entry, x_offset_kP_entry;
    nt::NetworkTableEntry dt_distance_kP_entry, dt_distance_kI_entry, dt_distance_kD_entry, dt_angle_kP_entry, dt_angle_kI_entry, dt_angle_kD_entry;
    nt::NetworkTableEntry if_kP_entry, if_kI_entry, if_kD_entry;
    nt::NetworkTableEntry vertical_power_entry, ball_count_entry;
    nt::NetworkTableEntry shooter_speed_entry, real_RPM_entry, target_RPM_entry, shooter_kP_entry, shooter_kI_entry, shooter_kD_entry, shooter_kF_entry;
    nt::NetworkTableEntry ll_aligned_entry, ll_sees_target_entry, angle_error_entry, ll_distance_kP, ll_distance_kI, ll_distance_kD, ll_angle_kP, ll_angle_kI, ll_angle_kD;
    nt::NetworkTableEntry speed_entry, time_entry, yeet_entry;
    nt::NetworkTableEntry move_delay_entry, shoot_delay_entry;

    double get_move_delay, get_shoot_delay;

  GreenScreen();
  void InitDefaultCommand() override;
};
