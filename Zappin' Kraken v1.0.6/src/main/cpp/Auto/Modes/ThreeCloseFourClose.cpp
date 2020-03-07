#include "Auto/Modes/ThreeCloseFourClose.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

ThreeCloseFourClose::ThreeCloseFourClose() {
  AddSequential(new ResetPosition(67, 174, 0));
  AddSequential(new AutoLimelightShoot(kFastFeedShooterTimeout, kShootDelay1));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));

  AddSequential(new DriveToPoint(100, 130, -40, -1, 1));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToPoint(129, 60, 0, -0.6));
  AddSequential(new DriveToPoint(129, 10, 0));

  AddSequential(new DriveToPoint(90, 50, -15, 0.7, 1));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperMid));
  AddSequential(new DriveToPoint(110, 67, 40));

  AddSequential(new DriveToPoint(89, 65, 80, -0.5, 0.5));
  AddSequential(new DriveToDistance(-17));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));

  AddSequential(new DriveToPoint(80, 130, -10, 0.7, 0.7));
  AddSequential(new DriveToPoint(67, 170, -5));
  AddSequential(new AutoLimelightShoot(kAutoLength, kShootDelay2));
}