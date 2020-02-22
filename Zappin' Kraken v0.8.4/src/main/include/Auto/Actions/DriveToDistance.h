#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class DriveToDistance : public frc::Command {
  private:
    PID m_PID;
    frc::Timer m_timer;
    double distance_target1, distance_target, ending_speed, acceleration_time;
    double starting_speed, starting_distance, speed, previous_time;

  public:
    DriveToDistance(double distance_input);
    DriveToDistance(double distance_input, double ending_speed_input);
    DriveToDistance(double distance_input, double ending_speed_input, double acceleration_time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
