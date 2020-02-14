
#include "Commands/Groups/LimelightAlign.h"

#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/LimelightDistancePID.h"
#include "Commands/Actions/AccelerateShooter.h"
#include "Commands/Actions/ShooterPID.h"

LimelightAlign::LimelightAlign() {
  AddParallel(new ShooterPID(1));
  AddSequential(new LimelightAnglePID);
  AddSequential(new LimelightDistancePID);
}