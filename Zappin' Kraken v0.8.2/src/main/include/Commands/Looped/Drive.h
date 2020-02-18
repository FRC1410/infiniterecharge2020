#pragma once

#include "Util/Libraries.h"

class Drive : public frc::Command {
  private:
    frc::Timer m_timer;
    double left_input, right_input;
    int invert_driving = 1;
    bool invert_driving_was_pressed, first_timer;

    double linear_displacement, x_position, z_position, prev_distance, previous_timer;

  public:
    Drive();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};