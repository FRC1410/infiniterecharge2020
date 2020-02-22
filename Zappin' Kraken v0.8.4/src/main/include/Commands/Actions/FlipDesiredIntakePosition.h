#pragma once

#include "Util/Libraries.h"

class FlipDesiredIntakePosition : public frc::Command {
  private:
    int desired_position;
    bool has_desired_position;

  public:
    FlipDesiredIntakePosition();
    FlipDesiredIntakePosition(int position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
