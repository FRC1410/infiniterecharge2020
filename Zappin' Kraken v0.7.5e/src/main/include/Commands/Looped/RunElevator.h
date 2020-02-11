#pragma once

#include "Util/Libraries.h"

class RunElevator : public frc::Command {
  public:
    RunElevator();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};