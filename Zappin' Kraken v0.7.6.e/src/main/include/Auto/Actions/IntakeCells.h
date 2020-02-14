#pragma once

#include "Util/Libraries.h"
#include "Util/PID.h"

class IntakeCells : public frc::Command {
  private:
    double run_time = 0;
    frc::Timer m_timer;
    bool intake_stop = true;
  public:
    IntakeCells();
    IntakeCells(double time);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};