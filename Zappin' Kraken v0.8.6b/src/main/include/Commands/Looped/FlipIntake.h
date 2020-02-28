#pragma once

#include "Util/Libraries.h"

class FlipIntake : public frc::Command {
  public:
    FlipIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
