#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class LimelightAnglePID : public frc::Command {
  private:
    PID m_PID;
    frc::Timer m_timer;
    double previous_timer;
    nt::NetworkTableEntry angle_error_entry;

  public:
    LimelightAnglePID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};