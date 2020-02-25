#pragma once

#include "Util/Libraries.h"

class AlertDriver : public frc::Command {
  private:
    frc::Timer m_timer;

  public:
    AlertDriver();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
