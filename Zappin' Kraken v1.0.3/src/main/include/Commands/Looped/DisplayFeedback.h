#pragma once

#include "Util/Libraries.h"

class DisplayFeedback : public frc::Command {
  private:
    double previous_RPM;
    int previous_dpad_input;
    bool manual_control_was_pressed;

  public:
    DisplayFeedback();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};