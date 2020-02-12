#include "Commands/Looped/FlipIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FlipIntake::FlipIntake() {
  Requires(&Robot::m_intake_flipper);
}

void FlipIntake::Initialize() {
  position_flipped = false;
  previous_position = Robot::m_intake_flipper.GetDesiredPosition();

  m_timer.Reset();
  m_timer.Stop();
}

void FlipIntake::Execute() {
  angle = Robot::m_intake_flipper.GetAngle() * pi/180;
  spring_angle = atan((kIntakeSpringXOffset + (kIntakeSpringDistanceOffset * sin(angle))) / (kIntakeSpringYOffset - (kIntakeSpringDistanceOffset * cos(angle))));
  force_compensation = (kIntakeFlipperSpringConstant * sin(pi - angle - spring_angle)) - (kIntakeFlipperGravityConstant * sin(angle));
  
  if ((position_flipped == false) && (Robot::m_intake_flipper.GetDesiredPosition() != previous_position)) {
    m_timer.Reset();
    m_timer.Stop();
    position_flipped = true;
  }
  if (position_flipped == true && Robot::m_intake_flipper.GetDesiredPosition() == false && Robot::m_intake_flipper.GetAngle() <= kIntakeUpThreshold) {
    m_timer.Start();
  }
  if (m_timer.Get() >= kIntakeFlipperUpDelay) {
    m_timer.Reset();
    m_timer.Stop();
    position_flipped = false;
  }

  if (Robot::m_intake_flipper.GetDesiredPosition() == true) {
    if (Robot::m_intake_flipper.GetAngle() < kIntakeDownThreshold) {
      Robot::m_intake_flipper.SetSpeed(kIntakeFlipperDownSpeed);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget, 0);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget, force_compensation);
    } else {
      Robot::m_intake_flipper.SetSpeed(0);
    }
  } else {
    if ((Robot::m_intake_flipper.GetAngle() > kIntakeUpThreshold) || ((m_timer.Get() < kIntakeFlipperUpDelay) && position_flipped == true)) {
      Robot::m_intake_flipper.SetSpeed(kIntakeFlipperUpSpeed);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget, 0);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget, force_compensation);
    } else {
      Robot::m_intake_flipper.SetSpeed(0);
    }
  }
  previous_position = Robot::m_intake_flipper.GetDesiredPosition();
}

bool FlipIntake::IsFinished() {
  return false;
}

void FlipIntake::End() {}

void FlipIntake::Interrupted() {}