#pragma once

#include "Util/Libraries.h"

class ActuateControlPanel : public frc::Command {
  public:
    ActuateControlPanel();
    ActuateControlPanel(frc::DoubleSolenoid::Value position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};