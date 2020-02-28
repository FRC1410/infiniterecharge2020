#pragma once

#include "Util/Libraries.h"

class RunStorage : public frc::Command {
  private:
    frc::Timer m_timer;

  public:
    RunStorage();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};