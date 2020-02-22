#include "Auto/Modes/BigKahunaTest.h"
#include "Auto/Actions/DriveToDistance.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/TurnToAngle.h"

BigKahunaTest::BigKahunaTest() {
  /*AddSequential(new ResetDriveEncoders);
  AddSequential(new DriveDistance(50, 0.3, 1));
  AddSequential(new DriveDistance(30, 0.5));
  AddSequential(new DriveDistance(25));
  AddSequential(new TurnToAngle(90));*/
  //AddSequential(new DriveDistance(100, 0.4));
  //AddSequential(new DriveDistance(100));

  AddSequential(new DriveToPoint(40, 60, 45, 0.5, 2));
  AddSequential(new DriveToPoint(60, 80, 0), 0);
}