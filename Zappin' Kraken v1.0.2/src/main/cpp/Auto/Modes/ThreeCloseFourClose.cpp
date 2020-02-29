#include "Auto/Modes/ThreeCloseFourClose.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToPoint.h"
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
  AddSequential(new DriveToPoint(137, 60, 0, -0.6));
  AddSequential(new DriveToPoint(137, 10, 0));

  AddSequential(new DriveToPoint(80, 40, -15, 0.7, 1));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperMid));
  AddSequential(new DriveToPoint(90, 70, 80));

  AddSequential(new DriveToPoint(80, 68, 80, -0.4, 0.4));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddSequential(new DriveToPoint(70, 66, 80));

  AddSequential(new DriveToPoint(80, 130, -10, 0.7, 1));
  AddSequential(new DriveToPoint(67, 170, 0));
  AddSequential(new AutoLimelightShoot(kAutoLength, kShootDelay2));
}