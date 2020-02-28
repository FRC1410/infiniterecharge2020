#pragma once

#include "Util/Libraries.h"

class AccelerateShooter : public frc::Command {
  private:
    frc::Timer m_timer;

  public:
    AccelerateShooter();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};