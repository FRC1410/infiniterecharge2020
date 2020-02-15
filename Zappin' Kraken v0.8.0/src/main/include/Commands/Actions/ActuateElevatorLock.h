#pragma once

#include "Util/Libraries.h"

class ActuateElevatorLock : public frc::Command {
  public:
    ActuateElevatorLock();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};