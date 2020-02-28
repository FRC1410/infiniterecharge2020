#pragma once

#include "Util/Libraries.h"

class RunElevator : public frc::Command {
  private:
    bool joystick_was_moved;

  public:
    RunElevator();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};