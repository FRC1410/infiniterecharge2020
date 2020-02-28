#pragma once

#include "Util/Libraries.h"

class AlertDriver : public frc::Command {
  private:
    bool run;

  public:
    AlertDriver();
    AlertDriver(bool stop_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
