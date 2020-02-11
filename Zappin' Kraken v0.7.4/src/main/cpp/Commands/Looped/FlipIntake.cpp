#include "Commands/Looped/FlipIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FlipIntake::FlipIntake() {
  Requires(&Robot::m_intake_flipper);
}

void FlipIntake::Initialize() {}

void FlipIntake::Execute() {
  angle = Robot::m_intake_flipper.GetAngle() * pi/180;
  spring_angle = atan((kIntakeSpringXOffset + (kIntakeSpringDistanceOffset * sin(angle))) / (kIntakeSpringYOffset - (kIntakeSpringDistanceOffset * cos(angle))));
  force_compensation = (kIntakeFlipperSpringConstant * sin(pi - angle - spring_angle)) - (kIntakeFlipperGravityConstant * sin(angle));
  if (Robot::m_intake_flipper.GetDesiredPosition() == true) {
    if (Robot::m_intake_flipper.GetAngle() < kIntakeDownThreshold) {
      Robot::m_intake_flipper.SetSpeed(0.15);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget, 0);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget, force_compensation);
    } else {
      Robot::m_intake_flipper.SetSpeed(0);
    }
  } else {
    if (Robot::m_intake_flipper.GetAngle() > kIntakeUpThreshold) {
      Robot::m_intake_flipper.SetSpeed(-0.15);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget, 0);
      //Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget, force_compensation);
    } else {
      Robot::m_intake_flipper.SetSpeed(0);
    }
  }
}

bool FlipIntake::IsFinished() {
  return false;
}

void FlipIntake::End() {}

void FlipIntake::Interrupted() {}