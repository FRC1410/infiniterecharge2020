#include "Auto/Modes/SixBallTrench.h"
#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Groups/AlignAndShoot.h"

#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/TurnToAngle.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/FlipDesiredIntakePosition.h"

#include "RobotMap/Constants.h"

SixBallTrench::SixBallTrench() {
  AddSequential(new FiveBallTrench);
  AddParallel(new FlipDesiredIntakePosition(kIntakeFlipperDown));
  AddSequential(new TurnToAngle(0), 1.5);
  AddSequential(new IntakeBalls);
  AddSequential(new DriveToDistance(-20, -0.4, 0.8));
  AddSequential(new DriveToDistance(-20), 2);
  AddParallel(new IntakeBalls(0), 0.254);
  AddParallel(new FlipDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new AlignAndShoot, 7);
  AddSequential(new TurnToAngle(55), 2.54);
}