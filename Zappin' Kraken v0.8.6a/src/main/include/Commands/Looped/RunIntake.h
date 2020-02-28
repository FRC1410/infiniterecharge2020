#pragma once

#include "Util/Libraries.h"

class RunIntake : public frc::Command {
  private:
    bool trigger_was_pressed;

  public:
    RunIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};