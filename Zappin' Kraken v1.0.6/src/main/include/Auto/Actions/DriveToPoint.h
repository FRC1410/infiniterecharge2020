#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class DriveToPoint : public frc::Command {
  private:
    PID m_angle_PID, m_offset_PID, m_distance_PID;

    frc::Timer m_timer;
    double x_target, z_target, angle_target, starting_speed, ending_speed, acceleration_time;
    double x_difference, z_difference, translated_x, translated_z, starting_translated_z;
    double linear_speed, rotational_speed, PID_angle_target, previous_time;

  public:
    DriveToPoint(double x_target_input, double z_target_input, double angle_target_input);
    DriveToPoint(double x_target_input, double z_target_input, double angle_target_input, double ending_speed_input);
    DriveToPoint(double x_target_input, double z_target_input, double angle_target_input, double ending_speed_input, double acceleration_time_input);
    void CalculatePosition();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};