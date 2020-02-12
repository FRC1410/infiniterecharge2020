#include "Commands/Actions/DebouncedLimelightAnglePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"
#include "RobotMap/Constants.h"

DebouncedLimelightAnglePID::DebouncedLimelightAnglePID() {
  Requires(&Robot::m_drivetrain);
}

void DebouncedLimelightAnglePID::Initialize() {
  m_PID.SetConstants(limelight_angle_kP, limelight_angle_kI, limelight_angle_kD);
  m_PID.ResetI();
  m_PID.ResetD();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void DebouncedLimelightAnglePID::Execute() {
  int angleSum = 0;
  int angleUninitialized = 0;
  for (int i = (sizeof(angleHist)/doubleSize); i > 0; i--) {     //Manipulate values
    angleHist[i] = angleHist[i - 1];
  }
  angleHist[0] = Robot::m_limelight.GetXAngle();
  
  for (int j = 0; j < (sizeof(angleHist)/doubleSize); j++) {     //Get Average
    if (angleHist[j] != 0) {
      angleSum += angleHist[j];
    } else {
      angleUninitialized++;
    }
  }
  double avAngle = angleSum/((sizeof(angleHist)/doubleSize) - angleUninitialized);
  
  Robot::m_drivetrain.SetCurvedArcadeSpeed(0, -m_PID.GetPID(avAngle, -kLimelightAngleOffset, m_timer.Get() - previous_timer));
  previous_timer = m_timer.Get();

  frc::SmartDashboard::PutNumber("Angle Error", Robot::m_limelight.GetXAngle() + kLimelightAngleOffset);
  frc::SmartDashboard::PutNumber("Average Angle Error", avAngle + kLimelightAngleOffset);
}

bool DebouncedLimelightAnglePID::IsFinished() {
  return (abs(Robot::m_limelight.GetXAngle() + kLimelightAngleOffset) < kLimelightAngleFinishedThreshold);
}

void DebouncedLimelightAnglePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void DebouncedLimelightAnglePID::Interrupted() {
  End();
}