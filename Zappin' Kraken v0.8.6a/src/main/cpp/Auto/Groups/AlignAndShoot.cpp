#include "Auto/Groups/AlignAndShoot.h"
#include "Commands/Groups/LimelightShoot.h"
#include "Commands/Actions/Shoot.h"
#include "Commands/Actions/ShooterPID.h"

AlignAndShoot::AlignAndShoot() {
  AddSequential(new LimelightShoot, 2.5);
  AddParallel(new ShooterPID, 4.5);
  AddSequential(new Shoot, 4.5);
  AddSequential(new ShooterPID(0), 0.254);
}