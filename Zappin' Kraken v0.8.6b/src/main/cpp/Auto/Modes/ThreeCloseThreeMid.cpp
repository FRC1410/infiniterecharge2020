#include "Auto/Modes/ThreeCloseThreeMid.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"
#include "Commands/Groups/LimelightShoot.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

ThreeCloseThreeMid::ThreeCloseThreeMid() {
  AddSequential(new ResetPosition(75, 174, 0));
  AddSequential(new LimelightShoot(kVerticalFeedShooterTimeout));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddSequential(new DriveToPoint(100, 130, -40, -0.4, 1));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToPoint(134, 60, 0, -0.4));
  AddSequential(new DriveToPoint(134, 16, 0));
  AddParallel(new IntakeBalls(0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new LimelightShoot(kVerticalFeedShooterTimeout));
}