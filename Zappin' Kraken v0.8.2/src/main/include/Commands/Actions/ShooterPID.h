#pragma once

#include "Util/Libraries.h"

class ShooterPID : public frc::Command {
  public:
    ShooterPID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};