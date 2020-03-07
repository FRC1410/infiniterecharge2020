#include "Auto/Modes/DriveOffLine.h"

#include "Auto/Actions/ResetPosition.h"
#include "Auto/Actions/DriveToDistance.h"

DriveOffLine::DriveOffLine() {
  AddSequential(new ResetPosition(75, 174, 0));
  AddSequential(new DriveToDistance(-20, -0.4, 0.8));
  AddSequential(new DriveToDistance(-20), 2);
}