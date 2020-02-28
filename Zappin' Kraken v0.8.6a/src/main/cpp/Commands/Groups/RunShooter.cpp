#include "Commands/Groups/RunShooter.h"

#include "Commands/Actions/AccelerateShooter.h"
#include "Commands/Actions/ShooterPID.h"

RunShooter::RunShooter() {
  //AddSequential(new AccelerateShooter);
  AddSequential(new ShooterPID);
}