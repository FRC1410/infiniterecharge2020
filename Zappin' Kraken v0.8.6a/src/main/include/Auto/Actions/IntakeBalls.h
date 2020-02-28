#pragma once

#include "Util/Libraries.h"

class IntakeBalls : public frc::Command {
  private:
    double speed;

  public:
    IntakeBalls();
    IntakeBalls(double time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};