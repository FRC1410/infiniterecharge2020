#pragma once

#include "Util/Libraries.h"

class TimerDelay : public frc::Command {
  public:
    TimerDelay();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};