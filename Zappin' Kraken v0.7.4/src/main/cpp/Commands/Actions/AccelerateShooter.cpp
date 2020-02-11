#include "Commands/Actions/AccelerateShooter.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

AccelerateShooter::AccelerateShooter(double target_speed_input) {
  Requires(&Robot::m_shooter);
  target_speed = target_speed_input;
}

void AccelerateShooter::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void AccelerateShooter::Execute() {
  Robot::m_shooter.SetSpeed((m_timer.Get() + 0.02) / kAccelerationTime);
}

bool AccelerateShooter::IsFinished() {
  return (Robot::m_shooter.GetRPM() >= target_RPM);
}

void AccelerateShooter::End() {}

void AccelerateShooter::Interrupted() {}