#include "Commands/Groups/RunShooter.h"

#include "Commands/Actions/AccelerateShooter.h"
#include "Commands/Actions/ShooterPID.h"

RunShooter::RunShooter() {
  AddSequential(new AccelerateShooter);
  AddSequential(new ShooterPID);
}

RunShooter::RunShooter(double target_RPM) {
  AddSequential(new AccelerateShooter);
  AddSequential(new ShooterPID(target_RPM));
}

RunShooter::RunShooter(double target_RPM, double acceleration_time) {
  AddSequential(new AccelerateShooter(acceleration_time));
  AddSequential(new ShooterPID(target_RPM));
}