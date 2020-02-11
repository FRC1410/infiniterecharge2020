#pragma once

#include "Util/Libraries.h"

class TimedDrive : public frc::Command {
  private:
    frc::Timer m_timer;
    double left_speed, right_speed, time;

  public:
    TimedDrive();
    TimedDrive(double speed_input, double time_input);
    TimedDrive(double left_speed_input, double right_speed_input, double time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};