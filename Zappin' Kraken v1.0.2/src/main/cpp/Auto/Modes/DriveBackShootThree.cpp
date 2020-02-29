#include "Auto/Modes/DriveBackShootThree.h"
#include "Auto/Modes/DriveOffLine.h"

#include "Commands/Groups/LimelightShoot.h"
#include "RobotMap/Tuning.h"

DriveBackShootThree::DriveBackShootThree() {
  AddSequential(new DriveOffLine);
  AddSequential(new LimelightShoot(kFeedShooterTimeout));
}