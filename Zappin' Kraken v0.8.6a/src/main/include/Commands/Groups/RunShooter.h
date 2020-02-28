#pragma once

#include "Util/Libraries.h"

class RunShooter : public frc::CommandGroup {
  public:
    RunShooter();
    RunShooter(double target_RPM);
    RunShooter(double target_RPM, double acceleration_time);
};