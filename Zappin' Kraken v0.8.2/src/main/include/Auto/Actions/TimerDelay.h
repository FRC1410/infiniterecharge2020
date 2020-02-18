#pragma once

#include "Util/Libraries.h"

class TimerDelay : public frc::Command {
  private:
    frc::Timer m_timer;
    double delay;
    
  public:
    TimerDelay(double input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};