#include "Commands/Groups/LimelightShoot.h"

#include "Commands/Groups/RunShooter.h"

#include "Commands/Actions/LimelightAnglePID.h"
#include "Commands/Actions/SmoothLimelightDistancePID.h"
#include "Commands/Actions/Shoot.h"
#include "Commands/Actions/ShooterPID.h"

#include "RobotMap/Tuning.h"

LimelightShoot::LimelightShoot() {
  AddParallel(new RunShooter);
  AddSequential(new LimelightAnglePID, kLimelightAngleTimeout);
  AddSequential(new SmoothLimelightDistancePID, kLimelightDistanceTimeout);
  AddSequential(new Shoot, kFeedShooterTimeout);
  AddSequential(new ShooterPID(0), 0.1);
}