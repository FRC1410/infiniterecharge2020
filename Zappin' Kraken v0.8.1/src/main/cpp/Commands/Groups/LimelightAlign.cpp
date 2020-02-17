#include "Commands/Groups/LimelightAlign.h"

#include "Commands/Groups/RunShooter.h"
#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/LimelightDistancePID.h"
#include "Commands/Actions/AlertDriver.h"

#include "Commands/Actions/DebouncedLimelightDistancePID.h"
#include "Commands/Actions/NewDebouncedLimelightDistancePID.h"

LimelightAlign::LimelightAlign() {
  AddSequential(new AlertDriver);
  AddParallel(new RunShooter);
  AddSequential(new LimelightAnglePID);
  //AddSequential(new LimelightDistancePID);
  AddSequential(new DebouncedLimelightDistancePID);
  //AddSequential(new NewDebouncedLimelightDistancePID);
}