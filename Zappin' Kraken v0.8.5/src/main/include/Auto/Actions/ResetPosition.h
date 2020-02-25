#pragma once

#include "Util/Libraries.h"

class ResetPosition : public frc::Command {
  private:
    double x, z, angle;

  public:
    ResetPosition(double x_input, double z_input, double angle_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};