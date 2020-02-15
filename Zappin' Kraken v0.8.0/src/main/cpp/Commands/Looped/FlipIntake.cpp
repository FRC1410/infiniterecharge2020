#include "Commands/Looped/FlipIntake.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

FlipIntake::FlipIntake() {
  Requires(&Robot::m_intake_flipper);
}

void FlipIntake::Initialize() {}

void FlipIntake::Execute() {
  kP = frc::SmartDashboard::GetNumber("Intake kP", intake_flipper_kP);
  kI = frc::SmartDashboard::GetNumber("Intake kI", intake_flipper_kI);
  kD = frc::SmartDashboard::GetNumber("Intake kD", intake_flipper_kD);
  Robot::m_intake_flipper.SetPIDConstants(kP, kI, kD);

  if (Robot::m_intake_flipper.GetDesiredPosition() == true) {
    if (Robot::m_intake_flipper.GetAngle() < kIntakeDownThreshold) {
      Robot::m_intake_flipper.SetPIDSpeed(kIntakeDownTarget, kIntakeFlipperGravityConstant * sin(Robot::m_intake_flipper.GetAngle() * pi/180));
    } else {
      Robot::m_intake_flipper.SetSpeed(0);
    }
  } else {
    if (Robot::m_intake_flipper.GetAngle() > kIntakeUpThreshold) {
      Robot::m_intake_flipper.SetPIDSpeed(kIntakeUpTarget, kIntakeFlipperGravityConstant * sin(Robot::m_intake_flipper.GetAngle() * pi/180));
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