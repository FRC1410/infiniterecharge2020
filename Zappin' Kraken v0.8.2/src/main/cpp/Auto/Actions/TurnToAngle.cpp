#include "Auto/Actions/TurnToAngle.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"

TurnToAngle::TurnToAngle(double angle) {
  Requires(&Robot::m_drivetrain);
  target_angle = fmod(fmod(angle - Robot::m_drivetrain.GetAngle() + 180, 360) + 360, 360) - 180 + Robot::m_drivetrain.GetAngle();
}

void TurnToAngle::Initialize() {
  m_PID.SetConstants(drivetrain_angle_kP, drivetrain_angle_kI, drivetrain_angle_kD);
  m_PID.ResetI();
  m_PID.ResetD();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void TurnToAngle::Execute() {
  Robot::m_drivetrain.SetCurvedArcadeSpeed(0, m_PID.GetPID(Robot::m_drivetrain.GetAngle(), target_angle, m_timer.Get() - previous_timer));
  previous_timer = m_timer.Get();
}

bool TurnToAngle::IsFinished() {
  return (abs(Robot::m_drivetrain.GetAngle() - target_angle) < kAngleFinishedThreshold);
}

void TurnToAngle::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void TurnToAngle::Interrupted() {
  End();
}