#pragma once

#include "Util/Libraries.h"

class FlipDesiredIntakePosition : public frc::Command {
  public:
    FlipDesiredIntakePosition();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
