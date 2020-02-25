#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"
#include "RobotMap/Tuning.h"

class DebouncedLimelightDistancePID : public frc::Command {
  private:
    PID m_distance_PID, m_angle_PID;
    frc::Timer m_timer, m_finished_timer;
    double linear_speed, rotational_speed, previous_timer, target_distance;

    double avDist;

    double distHist[10];

    double kP, kI, kD;

  public:
    DebouncedLimelightDistancePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};