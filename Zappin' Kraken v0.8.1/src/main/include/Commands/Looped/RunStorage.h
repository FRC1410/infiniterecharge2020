#pragma once

#include "Util/Libraries.h"

class RunStorage : public frc::Command {
  private:
    double speed_input;

  public:
    RunStorage();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};