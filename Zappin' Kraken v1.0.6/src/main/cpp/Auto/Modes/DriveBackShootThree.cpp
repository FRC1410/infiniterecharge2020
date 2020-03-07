#include "Auto/Modes/DriveBackShootThree.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"

#include "Commands/Groups/LimelightShoot.h"
#include "RobotMap/Tuning.h"

DriveBackShootThree::DriveBackShootThree() {
  AddSequential(new ResetPosition(75, 174, 0));
  AddSequential(new DriveToDistance(-30, -0.5, 1));
  AddSequential(new DriveToDistance(-30), 2);
  AddSequential(new LimelightShoot(kFeedShooterTimeout));
}