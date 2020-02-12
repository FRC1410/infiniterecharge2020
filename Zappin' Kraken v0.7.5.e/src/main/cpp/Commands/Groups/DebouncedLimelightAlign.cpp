
#include "Commands/Groups/DebouncedLimelightAlign.h"

#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/DebouncedLimelightDistancePID.h"
#include "Commands/Actions/AccelerateShooter.h"
#include "Commands/Actions/ShooterPID.h"

DebouncedLimelightAlign::DebouncedLimelightAlign() {
  AddParallel(new ShooterPID(1));
  AddSequential(new LimelightAnglePID);
  AddSequential(new DebouncedLimelightDistancePID);
}