#include "Auto/Modes/BigKahunaTest.h"
#include "Auto/Actions/DriveDistance.h"

BigKahunaTest::BigKahunaTest() {
  frc::SmartDashboard::PutString("Auto Running?", "yep");
  AddSequential(new DriveDistance(100, 0.3, 3));
  AddSequential(new DriveDistance(100, 0.01, 3));
}