#pragma once

#include "Util/Libraries.h"

class TimerDelay : public frc::Command {
  private:
    int type;
  public:
    TimerDelay();
    TimerDelay(int delay_type);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};