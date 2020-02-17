#pragma once

#include "Util/Libraries.h"

class ActivateStorage : public frc::Command {
  private:
    frc::Timer m_timer;
    double time;

  public:   
    ActivateStorage();
    ActivateStorage(double time_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};