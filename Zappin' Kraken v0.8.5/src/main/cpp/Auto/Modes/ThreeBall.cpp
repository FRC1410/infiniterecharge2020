#include "Auto/Modes/ThreeBall.h"
#include "Auto/Modes/DriveOffLine.h"
#include "Auto/Groups/AlignAndShoot.h"

ThreeBall::ThreeBall() {
  AddSequential(new DriveOffLine);
  AddSequential(new AlignAndShoot, 7);
}