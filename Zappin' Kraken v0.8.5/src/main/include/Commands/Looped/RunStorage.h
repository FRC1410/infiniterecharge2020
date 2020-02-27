#pragma once

#include "Util/Libraries.h"

class RunStorage : public frc::Command {
  private:
    frc::Timer m_timer, m_measure_timer;
    bool sensor_was_read, follow_through, disabled_was_pressed;

  public:
    RunStorage();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};