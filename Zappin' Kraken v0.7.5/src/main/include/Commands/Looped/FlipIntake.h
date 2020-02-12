#pragma once

#include "Util/Libraries.h"

class FlipIntake : public frc::Command {
  private:
    frc::Timer m_timer;
    double angle, spring_angle, force_compensation;
    bool position_flipped, previous_position;

  public:
    FlipIntake();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
