#include "Auto/Modes/ShootThreeDriveBack.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"

#include "Commands/Groups/LimelightShoot.h"
#include "RobotMap/Tuning.h"

ShootThreeDriveBack::ShootThreeDriveBack() {
  AddSequential(new ResetPosition(75, 174, 0));
  AddSequential(new LimelightShoot(kVerticalFeedShooterTimeout));
  AddSequential(new DriveToDistance(-20, -0.4, 0.8));
  AddSequential(new DriveToDistance(-20), 2);
}