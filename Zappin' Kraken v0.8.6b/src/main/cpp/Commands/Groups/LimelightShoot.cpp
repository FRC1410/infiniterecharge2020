#include "Commands/Groups/LimelightShoot.h"

#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/SmoothLimelightDistancePID.h"
#include "Commands/Actions/Shoot.h"
#include "Commands/Actions/ShooterPID.h"

#include "RobotMap/Tuning.h"

LimelightShoot::LimelightShoot() {
  AddParallel(new ShooterPID);
  AddSequential(new LimelightAnglePID, kLimelightAngleTimeout);
  AddSequential(new SmoothLimelightDistancePID, kLimelightDistanceTimeout);
  AddSequential(new Shoot);
}

LimelightShoot::LimelightShoot(double shoot_timeout) {
  AddParallel(new ShooterPID);
  AddSequential(new LimelightAnglePID, kLimelightAngleTimeout);
  AddSequential(new SmoothLimelightDistancePID, kLimelightDistanceTimeout);
  AddSequential(new Shoot, shoot_timeout);
  AddSequential(new ShooterPID(0));
}