#pragma once

#include "Util/Libraries.h"

class ActivateCamera : public frc::Command {
  private:
    bool run;

  public:
    ActivateCamera();
    ActivateCamera(bool off_input);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};