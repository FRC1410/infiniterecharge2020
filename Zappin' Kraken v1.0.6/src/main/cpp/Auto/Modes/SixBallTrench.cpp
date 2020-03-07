#include "Auto/Modes/SixBallTrench.h"
#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/TurnToAngle.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

SixBallTrench::SixBallTrench() {
  AddSequential(new FiveBallTrench);
  AddSequential(new TurnToAngle(0), 0.7);
  AddParallel(new IntakeBalls);

  AddSequential(new DriveToDistance(-20, -0.4, 0.6));
  AddSequential(new DriveToDistance(-20), 2);
  AddSequential(new AutoLimelightShoot(kFeedShooterTimeout, kShootDelay2));
  AddParallel(new IntakeBalls(0));
  //AddSequential(new TurnToAngle(55), 2.54);
}