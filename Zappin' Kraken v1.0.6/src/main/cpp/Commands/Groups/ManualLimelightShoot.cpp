#include "Commands/Groups/ManualLimelightShoot.h"

#include "Commands/Groups/LimelightShoot.h"

#include "Commands/Actions/ActivateCamera.h"
#include "Commands/Actions/AlertDriver.h"

#include "Commands/Actions/ShooterPID.h"
#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/SmoothLimelightDistancePID.h"
#include "Commands/Actions/Shoot.h"

ManualLimelightShoot::ManualLimelightShoot() {
  AddParallel(new ActivateCamera);
  AddParallel(new AlertDriver);
  AddParallel(new ShooterPID);
  AddSequential(new LimelightAnglePID, kLimelightAngleTimeout);
  AddSequential(new SmoothLimelightDistancePID, kLimelightDistanceTimeout);
  AddSequential(new Shoot);
}