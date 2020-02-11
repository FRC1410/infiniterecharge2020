#pragma once

#include "Util/Libraries.h"

class Shoot : public frc::Command {
  private:
    frc::Timer m_timer;

  public:
    Shoot();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
