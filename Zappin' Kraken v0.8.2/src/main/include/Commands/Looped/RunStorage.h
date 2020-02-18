#pragma once

#include "Util/Libraries.h"

class RunStorage : public frc::Command {
  private:
    frc::Timer m_timer;
    bool outer_sensor_was_read, inner_sensor_was_read, follow_through;
    int storage_sequence;

  public:
    RunStorage();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};