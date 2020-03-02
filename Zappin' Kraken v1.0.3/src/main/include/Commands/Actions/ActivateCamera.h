#pragma once

#include "Util/Libraries.h"

class ActivateCamera : public frc::Command {
  public:
    ActivateCamera();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};