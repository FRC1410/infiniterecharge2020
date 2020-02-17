#pragma once

#include "Util/Libraries.h"

class IntakeBalls : public frc::Command {
  private:
    frc::Timer m_timer;
    double time;

  public:
    IntakeBalls();
    IntakeBalls(double time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};