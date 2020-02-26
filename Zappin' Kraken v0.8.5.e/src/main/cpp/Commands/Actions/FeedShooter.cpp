/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Actions/ToggleElevatorBrake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"
#include "Util/Libraries.h"


ToggleElevatorBrake::ToggleElevatorBrake() {
  Requires(&Robot::m_elevator);
}

// Called just before this Command runs the first time
void ToggleElevatorBrake::Initialize() {
  Robot::m_elevator.Toggle();
}

// Called repeatedly when this Command is scheduled to run
void ToggleElevatorBrake::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleElevatorBrake::IsFinished() { return false; }

// Called once after isFinished returns true
void ToggleElevatorBrake::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleElevatorBrake::Interrupted() {
  End();
}
