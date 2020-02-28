#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"
#include "RobotMap/Tuning.h"

class SmoothLimelightDistancePID : public frc::Command {
  private:
    PID m_distance_PID, m_angle_PID;
    frc::Timer m_timer, m_finished_timer;
    double linear_speed, rotational_speed, previous_timer, target_distance;

    double distance_history[kSmoothLimelightDistanceIndex];
    double average_distance, distance_sum;
    int uninitialized;

  public:
    SmoothLimelightDistancePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};