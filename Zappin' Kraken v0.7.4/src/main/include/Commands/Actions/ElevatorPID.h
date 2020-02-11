#pragma once

#include "Util/Libraries.h"

class ElevatorPID : public frc::Command {
  public:
    ElevatorPID();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
