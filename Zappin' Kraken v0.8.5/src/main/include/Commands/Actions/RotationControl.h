#pragma once

#include "Util/Libraries.h"

class RotationControl : public frc::Command {
  private:
    int eighth_rotations, current_color;
    
  public:
    RotationControl();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};