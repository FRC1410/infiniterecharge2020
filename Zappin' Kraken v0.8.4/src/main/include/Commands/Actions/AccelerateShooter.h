#pragma once

#include "Util/Libraries.h"

class AccelerateShooter : public frc::Command {
  private:
    frc::Timer m_timer;
    double target_RPM, acceleration_time;

  public:
    AccelerateShooter();
    AccelerateShooter(double target_RPM_input);
    AccelerateShooter(double target_RPM_input, double acceleration_time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};