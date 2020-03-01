#pragma once

#include "Util/Libraries.h"

class ShooterPID : public frc::Command {
  private:
    bool run;

  public:
    ShooterPID();
    ShooterPID(bool run_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};