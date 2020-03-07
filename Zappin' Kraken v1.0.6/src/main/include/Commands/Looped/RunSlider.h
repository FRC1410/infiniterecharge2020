#pragma once

#include "Util/Libraries.h"

class RunSlider : public frc::Command {
  public:
    RunSlider();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};