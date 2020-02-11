#pragma once

#include "Util/Libraries.h"

class RunStorage : public frc::Command {
  private:
    bool outer_sensor_was_read, inner_sensor_was_read;

  public:
    RunStorage();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};