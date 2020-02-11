#pragma once

#include "Util/Libraries.h"

class ShooterPID : public frc::Command {
  private:
    double target_RPM;

  public:
    ShooterPID(double RPM_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
