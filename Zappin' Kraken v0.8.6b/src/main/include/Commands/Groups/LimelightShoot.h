#pragma once

#include "Util/Libraries.h"

class LimelightShoot : public frc::CommandGroup {
  public:
    LimelightShoot();
    LimelightShoot(double shoot_timeout);
};