#include "Auto/Modes/ThreeCloseThreeMid.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

ThreeCloseThreeMid::ThreeCloseThreeMid() {
  AddSequential(new ResetPosition(67, 174, 0));
  AddSequential(new AutoLimelightShoot(kFeedShooterTimeout, kShootDelay1));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddSequential(new DriveToPoint(100, 130, -40, -0.6, 1));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToPoint(137, 60, 0, -0.6));
  AddSequential(new DriveToPoint(137, 10, 0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new AutoLimelightShoot(kSlowFeedShooterTimeout, kShootDelay2));
  AddParallel(new IntakeBalls(0));
}