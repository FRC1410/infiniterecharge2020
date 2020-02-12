#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"
#include "RobotMap/Tuning.h"

class DebouncedLimelightDistancePID : public frc::Command {
  private:
    PID m_angle_PID;
    PID m_distance_PID;
    frc::Timer m_timer;
    double linear_speed, rotational_speed, previous_timer, target_distance;

    double avDist;

    double distHist[LimelightDistanceIndex];
    double angleHist[LimelightAngleIndex];

  public:
    DebouncedLimelightDistancePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};