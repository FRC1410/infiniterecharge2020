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

    int bigData[LimelightDistanceIndex];
    double distHist[LimelightDistanceIndex];
    double angleHist[LimelightAngleIndex];
    double size = 0;
    double size2 = 0;
    int option = 0;
    
    int distUninitialized = 0;
    int debounce_incrementer = 0;

  public:
    DebouncedLimelightDistancePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};