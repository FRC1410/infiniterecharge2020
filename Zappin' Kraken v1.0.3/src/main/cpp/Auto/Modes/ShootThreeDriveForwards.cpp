#include "Auto/Modes/ShootThreeDriveForwards.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

ShootThreeDriveForwards::ShootThreeDriveForwards() {
  AddSequential(new ResetPosition(75, 174, 0));
  AddSequential(new AutoLimelightShoot(kFeedShooterTimeout, kShootDelay1));
  AddSequential(new DriveToDistance(30, 0.5, 1));
  AddSequential(new DriveToDistance(30), 2);
}