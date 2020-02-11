#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class DriveDistance : public frc::Command {
  private:
    PID m_PID;
    frc::Timer m_timer;
    double distance_target, ending_speed, acceleration_time;
    double starting_speed, starting_distance, speed, previous_time;

  public:
    DriveDistance(double distance_input);
    DriveDistance(double distance_input, double ending_speed_input);
    DriveDistance(double distance_input, double ending_speed_input, double acceleration_time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
