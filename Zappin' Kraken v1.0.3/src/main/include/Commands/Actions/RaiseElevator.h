#pragma once

#include "Util/Libraries.h"

class RaiseElevator : public frc::Command {
  private:
    double target_height;

  public:
    RaiseElevator(double target);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};