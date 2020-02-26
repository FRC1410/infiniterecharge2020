#include "Util/PID.h"

PID::PID() {
  kP = 0;
  kI = 0;
  kD = 0;
  ResetI();
  ResetD();
}

void PID::SetConstants(double kP_input, double kI_input, double kD_input) {
  kP = kP_input;
  kI = kI_input;
  kD = kD_input;
}

double PID::GetPID(double current, double target, double dt) {
  error = target - current;
  P = error * kP;
  I += error * kI * dt;
  if (D_ran == true) {
    D = (error - previous_error) * kD * dt;
  } else {
    D = 0;
  }
  previous_error = error;
  D_ran = true;

  return P + I + D;
}

void PID::ResetI() {
  I = 0;
}

void PID::ResetD() {
  D_ran = false;
}