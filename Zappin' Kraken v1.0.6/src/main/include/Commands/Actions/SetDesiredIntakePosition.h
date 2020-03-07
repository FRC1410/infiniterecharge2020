#pragma once

#include "Util/Libraries.h"

class SetDesiredIntakePosition : public frc::Command {
  private:
    int desired_position;

  public:
    SetDesiredIntakePosition(int position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};