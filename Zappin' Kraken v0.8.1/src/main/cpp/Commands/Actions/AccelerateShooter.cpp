#include "Commands/Actions/AccelerateShooter.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

AccelerateShooter::AccelerateShooter() {
  Requires(&Robot::m_shooter);
}

void AccelerateShooter::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void AccelerateShooter::Execute() {
  Robot::m_shooter.SetSpeed((m_timer.Get() + 0.02) / kAccelerationTime);
}

bool AccelerateShooter::IsFinished() {
  return (Robot::m_shooter.GetRPM() >= Robot::m_limelight.GetNearestRPMProfile());
}

void AccelerateShooter::End() {}

void AccelerateShooter::Interrupted() {
  Robot::m_shooter.SetSpeed(0);
}