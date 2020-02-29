#pragma once

#include "Util/Libraries.h"

class Controller {
  private:
    double raw_magnitude;

  public:
    Controller();
    double ApplyDeadzone(int controller, int axis, double joystick_deadzone, double trigger_threshold);
};