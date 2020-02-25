#pragma once

#include "Util/Libraries.h"

class ShooterPID : public frc::Command {
  private:
    double target_RPM, count;

  public:
    ShooterPID();
    ShooterPID(double target_RPM_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};