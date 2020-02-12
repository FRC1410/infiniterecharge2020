#include "Util/Controller.h"

Controller::Controller() {}

double Controller::ApplyDeadzone(int controller, int axis, double joystick_deadzone, double trigger_threshold) {
  if (axis == 1 || axis == 5) {
    raw_magnitude = sqrt(pow(frc::Joystick{controller}.GetRawAxis(axis), 2) + pow(frc::Joystick{controller}.GetRawAxis(axis - 1), 2));
    if (raw_magnitude <= joystick_deadzone) {
      return 0;
    } else {
      return -((raw_magnitude - joystick_deadzone) / (1 - joystick_deadzone)) * (frc::Joystick{controller}.GetRawAxis(axis) / raw_magnitude);
    }
  } else if (axis == 0 || axis == 4) {
    raw_magnitude = sqrt(pow(frc::Joystick{controller}.GetRawAxis(axis), 2) + pow(frc::Joystick{controller}.GetRawAxis(axis + 1), 2));
    if (raw_magnitude <= joystick_deadzone) {
      return 0;
    } else {
      return ((raw_magnitude - joystick_deadzone) / (1 - joystick_deadzone)) * (frc::Joystick{controller}.GetRawAxis(axis) / raw_magnitude);
    }
  } else {
    return frc::Joystick{controller}.GetRawAxis(axis);
  }
}