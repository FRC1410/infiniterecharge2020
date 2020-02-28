#include "Auto/Modes/BigKahunaTest.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/TurnToAngle.h"

BigKahunaTest::BigKahunaTest() {
  AddSequential(new DriveToPoint(40, 60, 45, 0.5, 2));
  AddSequential(new DriveToPoint(60, 80, 0), 0);
}