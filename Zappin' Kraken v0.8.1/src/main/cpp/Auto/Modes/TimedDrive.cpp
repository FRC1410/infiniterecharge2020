#include "Auto/Modes/TimedDrive.h"
#include "Robot.h"
#include "RobotMap/Constants.h"

TimedDrive::TimedDrive() {
  Requires(&Robot::m_drivetrain);
  left_speed = -1;
  right_speed = -1;
  time = -1;
}

TimedDrive::TimedDrive(double speed_input, double time_input) {
  Requires(&Robot::m_drivetrain);
  left_speed = speed_input;
  right_speed = speed_input;
  time = time_input;
}

TimedDrive::TimedDrive(double left_speed_input, double right_speed_input, double time_input) {
  Requires(&Robot::m_drivetrain);
  left_speed = left_speed_input;
  right_speed = right_speed_input;
  time = time_input;
}

void TimedDrive::Initialize() {
  /*left_speed = frc::SmartDashboard::GetNumber("Speed", kTimedDriveDefaultSpeed);
  right_speed = left_speed;
  time = frc::SmartDashboard::GetNumber("Time", kTimedDriveDefaultTime);*/

  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  yeet_entry = table->GetEntry("yeet");
  speed_entry = table->GetEntry("Speed");
  time_entry = table->GetEntry("Time");

  //if (left_speed < 0) {
    left_speed = speed_entry.GetDouble(0);//why doesn't this work?
    right_speed = left_speed;
  //}
  //if (time < 0) {
    time_entry.SetDouble(kTimedDriveDefaultTime);
    //time = frc::SmartDashboard::GetNumber("Time", kTimedDriveDefaultTime);
  //}

  m_timer.Reset();
  m_timer.Start();
}

void TimedDrive::Execute() {
  frc::SmartDashboard::PutBoolean("yeet", true);
  Robot::m_drivetrain.SetCurvedSpeed(left_speed, right_speed);
}

bool TimedDrive::IsFinished() {
  return (m_timer.Get() >= time);
}

void TimedDrive::End() {
  frc::SmartDashboard::PutBoolean("yeet", false);
  Robot::m_drivetrain.SetCurvedSpeed(0, 0);
}

void TimedDrive::Interrupted() {
  End();
}