#include "Auto/Modes/SixBallTrench.h"
#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/TurnToAngle.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Groups/LimelightShoot.h"
#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

SixBallTrench::SixBallTrench() {
  AddSequential(new FiveBallTrench);
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddSequential(new TurnToAngle(0), 1.5);
  AddSequential(new IntakeBalls);
  AddSequential(new DriveToDistance(-20, -0.4, 0.8));
  AddSequential(new DriveToDistance(-20), 2);
  AddParallel(new IntakeBalls(0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new LimelightShoot(kVerticalFeedShooterTimeout));
  AddSequential(new TurnToAngle(55), 2.54);
}