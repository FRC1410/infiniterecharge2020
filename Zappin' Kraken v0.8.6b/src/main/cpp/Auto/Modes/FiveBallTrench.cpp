#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Groups/LimelightShoot.h"
#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FiveBallTrench::FiveBallTrench() {
  AddSequential(new ResetPosition(133.875, 174, 0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToDistance(-100, -0.5, 1));
  AddSequential(new DriveToDistance(-25), 2);
  AddParallel(new IntakeBalls(0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new LimelightShoot(kFeedShooterTimeout));
}