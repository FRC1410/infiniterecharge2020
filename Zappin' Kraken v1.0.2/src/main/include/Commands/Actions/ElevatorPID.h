#pragma once

#include "Util/Libraries.h"

class ElevatorPID : public frc::Command {
  private:
    double target_height;

  public:
    ElevatorPID(double target);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
