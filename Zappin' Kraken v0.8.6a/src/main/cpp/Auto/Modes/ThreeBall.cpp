#include "Auto/Modes/ThreeBall.h"
#include "Auto/Modes/DriveOffLine.h"
#include "Commands/Groups/LimelightShoot.h"

ThreeBall::ThreeBall() {
  AddSequential(new DriveOffLine);
  AddSequential(new LimelightShoot, 5);
  //AddSequential(new DriveOffLine);
}