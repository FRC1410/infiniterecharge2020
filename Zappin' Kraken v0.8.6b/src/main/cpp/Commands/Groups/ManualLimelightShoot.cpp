#include "Commands/Groups/ManualLimelightShoot.h"

#include "Commands/Groups/LimelightShoot.h"

#include "Commands/Actions/ActivateCamera.h"
#include "Commands/Actions/AlertDriver.h"

ManualLimelightShoot::ManualLimelightShoot() {
  AddParallel(new ActivateCamera);
  AddParallel(new AlertDriver);
  AddSequential(new LimelightShoot);
}