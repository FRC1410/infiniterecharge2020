#pragma once

#include "Util/Libraries.h"

class FlipDesiredIntakePosition : public frc::Command {
  private:
    bool desired_position, has_desired_position;

  public:
    FlipDesiredIntakePosition();
    FlipDesiredIntakePosition(bool position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
