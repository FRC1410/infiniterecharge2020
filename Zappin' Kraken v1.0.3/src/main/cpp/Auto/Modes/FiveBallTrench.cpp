#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Groups/AutoLimelightShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/IntakeBalls.h"
#include "Auto/Actions/TimerDelay.h"

#include "Commands/Actions/SetDesiredIntakePosition.h"

#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FiveBallTrench::FiveBallTrench() {
  AddSequential(new ResetPosition(133.875, 174, 0));
  AddParallel(new SetDesiredIntakePosition(kIntakeFlipperDown));
  AddParallel(new IntakeBalls);

  AddSequential(new DriveToDistance(-105, -0.75, 1));
  AddSequential(new DriveToDistance(-35), 2);
  AddSequential(new AutoLimelightShoot(kSlowFeedShooterTimeout, kShootDelay1));
  AddSequential(new IntakeBalls(0));
}