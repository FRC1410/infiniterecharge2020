#include "Commands/Actions/AccelerateShooter.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

AccelerateShooter::AccelerateShooter() {
  Requires(&Robot::m_shooter);
  acceleration_time = kAccelerationTime;
  target_RPM = -1;
}

AccelerateShooter::AccelerateShooter(double target_RPM_input) {
  Requires(&Robot::m_shooter);
  target_RPM = target_RPM_input;
  acceleration_time = kAccelerationTime;
}

AccelerateShooter::AccelerateShooter(double target_RPM_input, double acceleration_time_input) {
  Requires(&Robot::m_shooter);
  target_RPM = target_RPM_input;
  acceleration_time = acceleration_time_input;
}

void AccelerateShooter::Initialize() {
  if (target_RPM < 0) {
    target_RPM = Robot::m_limelight.GetNearestRPMProfile();
  }
  m_timer.Reset();
  m_timer.Start();
}

void AccelerateShooter::Execute() {
  Robot::m_shooter.SetSpeed((m_timer.Get() + 0.02) / acceleration_time);
}

bool AccelerateShooter::IsFinished() {
  return (Robot::m_shooter.GetRPM() >= target_RPM);
}

void AccelerateShooter::End() {}

void AccelerateShooter::Interrupted() {
  Robot::m_shooter.SetSpeed(0);
}