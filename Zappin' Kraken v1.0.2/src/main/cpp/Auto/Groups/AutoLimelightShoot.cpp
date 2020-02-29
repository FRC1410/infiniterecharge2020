#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/TimerDelay.h"

#include "Commands/Groups/LimelightShoot.h"

#include "Commands/Actions/ActivateCamera.h"
#include "Commands/Actions/ShooterPID.h"
#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/SmoothLimelightDistancePID.h"
#include "Commands/Actions/Shoot.h"

AutoLimelightShoot::AutoLimelightShoot(double shoot_timeout, int delay_type_input) {
  AddParallel(new ActivateCamera);
  AddParallel(new ShooterPID);
  AddSequential(new LimelightAnglePID, kLimelightAngleTimeout);
  AddSequential(new SmoothLimelightDistancePID, kLimelightDistanceTimeout);
  AddSequential(new TimerDelay(delay_type_input));
  AddSequential(new Shoot, shoot_timeout);
  AddSequential(new ShooterPID(0));
}