#include "Auto/Modes/BigKahunaTest.h"
#include "Auto/Actions/DriveDistance.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/DriveToPoint.h"
#include "Auto/Actions/DriveToPoint.h"

BigKahunaTest::BigKahunaTest() {
  frc::SmartDashboard::PutString("Auto Running?", "yep");
  AddSequential(new DriveDistance(100, 0.3, 3));
  //AddSequential(new DriveDistance(100, 0.01, 3));

  //AddSequential(new DriveToPoint(40, 60, 45, 0.5, 2));
  //AddSequential(new DriveToPoint(80, 120, 0));
}