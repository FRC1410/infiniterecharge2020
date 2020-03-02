#pragma once

#include "Util/Libraries.h"

class AutoLimelightShoot : public frc::CommandGroup {
  private:
    int delay_type;

  public:
    AutoLimelightShoot(double shoot_timeout, int delay_type_input);
};