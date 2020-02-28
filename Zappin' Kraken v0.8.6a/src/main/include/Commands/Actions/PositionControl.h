#pragma once

#include "Util/Libraries.h"

class PositionControl : public frc::Command {
  private:
    frc::Timer m_rumble_timer, m_delay_timer;
    int offset, target, current;

  public:
    PositionControl(int offset_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};