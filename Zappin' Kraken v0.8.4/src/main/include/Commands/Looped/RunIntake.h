#pragma once

#include "Util/Libraries.h"

class RunIntake : public frc::Command {
  public:
    RunIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};