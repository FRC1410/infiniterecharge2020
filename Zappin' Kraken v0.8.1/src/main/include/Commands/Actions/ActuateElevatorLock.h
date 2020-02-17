#pragma once

#include "Util/Libraries.h"

class ActuateElevatorLock : public frc::Command {
  public:
    ActuateElevatorLock();
    ActuateElevatorLock(bool position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};