/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Actions/FeedShooter.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

FeedShooter::FeedShooter() {
  Requires(&Robot::m_storage);
}

// Called just before this Command runs the first time
void FeedShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FeedShooter::Execute() {
  Robot::m_storage.SetSpeed(kStorageFeedShooterHorizontalSpeed, kStorageFeedShooterVerticalSpeed);
  Robot::m_storage.SetBallCount(0);
}

// Make this return true when this Command no longer needs to run execute()
bool FeedShooter::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void FeedShooter::End() {
  Robot::m_storage.SetSpeed(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeedShooter::Interrupted() {
  End();
}
