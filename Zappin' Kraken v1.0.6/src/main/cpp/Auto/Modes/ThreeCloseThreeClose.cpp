#include "Auto/Modes/ThreeCloseThreeClose.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

ThreeCloseThreeClose::ThreeCloseThreeClose() {
  AddSequential(new ResetPosition(67, 174, 0));
  AddSequential(new AutoLimelightShoot(kFeedShooterTimeout, kShootDelay1));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown), 0.2);

  AddSequential(new DriveToPoint(100, 130, -40, -0.8, 1));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToPoint(129, 60, 0, -0.4));
  AddSequential(new DriveToPoint(129, 10, 0));

  AddSequential(new DriveToPoint(110, 70, -30, 1, 1));
  AddSequential(new DriveToPoint(80, 120, -25, 0.6));
  AddSequential(new DriveToPoint(67, 170, 0));
  AddSequential(new AutoLimelightShoot(kAutoLength, kShootDelay2));
}