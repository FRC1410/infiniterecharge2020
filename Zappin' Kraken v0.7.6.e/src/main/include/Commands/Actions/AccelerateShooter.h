#pragma once

#include "Util/Libraries.h"

class AccelerateShooter : public frc::Command {
  private:
    frc::Timer m_timer;
    double target_speed;

  public:
    AccelerateShooter(double target_speed_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
