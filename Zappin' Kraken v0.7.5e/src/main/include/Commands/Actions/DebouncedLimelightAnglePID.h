#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"
#include "RobotMap/Tuning.h"

class DebouncedLimelightAnglePID : public frc::Command {
  private:
    PID m_PID;
    frc::Timer m_timer;
    double previous_timer;

    double angleHist[LimelightAngleIndex];

  public:
    DebouncedLimelightAnglePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};