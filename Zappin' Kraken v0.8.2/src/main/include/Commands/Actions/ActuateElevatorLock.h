#pragma once

#include "Util/Libraries.h"

class ActuateElevatorLock : public frc::Command {
  private:
    bool desired_position, has_desired_position;

  public:
    ActuateElevatorLock();
    ActuateElevatorLock(bool position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};