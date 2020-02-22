#include "Auto/Modes/FiveBallTrench.h"

#include "Auto/Groups/AlignAndShoot.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/IntakeBalls.h"

#include "Commands/Actions/FlipDesiredIntakePosition.h"

#include "RobotMap/Constants.h"

FiveBallTrench::FiveBallTrench() {
  AddSequential(new ResetPosition(133.875, 174, 0));
  AddParallel(new FlipDesiredIntakePosition(kIntakeFlipperDown));
  AddParallel(new IntakeBalls);
  AddSequential(new DriveToDistance(-100, -0.5, 1));
  AddSequential(new DriveToDistance(-25), 2);
  AddParallel(new IntakeBalls(0), 0.254);
  AddParallel(new FlipDesiredIntakePosition(kIntakeFlipperUp));
  AddSequential(new AlignAndShoot, 7);
}