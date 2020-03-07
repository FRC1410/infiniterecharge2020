#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class TurnToAngle : public frc::Command {
  private:
    PID m_PID;
    frc::Timer m_timer;
    double target_angle, previous_timer;

  public:
    TurnToAngle(double angle);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};