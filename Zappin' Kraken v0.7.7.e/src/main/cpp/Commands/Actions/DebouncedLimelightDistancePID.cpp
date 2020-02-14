#include "Commands/Actions/DebouncedLimelightDistancePID.h"
#include "Robot.h"
#include "RobotMap/Tuning.h"
#include "RobotMap/Constants.h"
#include <math.h>
#include <algorithm> 

DebouncedLimelightDistancePID::DebouncedLimelightDistancePID() {
  Requires(&Robot::m_drivetrain);
}

void DebouncedLimelightDistancePID::Initialize() {
  m_angle_PID.SetConstants(limelight_angle_kP, limelight_angle_kI, limelight_angle_kD);
  m_angle_PID.ResetI();
  m_angle_PID.ResetD();
  
  m_distance_PID.SetConstants(limelight_distance_kP, limelight_distance_kI, limelight_distance_kD);
  m_distance_PID.ResetI();
  m_distance_PID.ResetD();

  target_distance = Robot::m_limelight.GetNearestDistanceTarget();

  previous_timer = 0;
  m_timer.Reset();
  m_timer.Start();
}

void DebouncedLimelightDistancePID::Execute() {

  std::sort(&bigData[0], &bigData[LimelightDistanceIndex]);

  size = sizeof(bigData)/sizeof(*bigData);

  for (int j=0; j < LimelightDistanceIndex; j++) {
    if (bigData[j] == 0) {
      distUninitialized++;
    }
  }

  double data[LimelightDistanceIndex - distUninitialized];

  size2 = sizeof(data)/sizeof(*data);

  for (int k = 0; k < int(size2); k++) {
    if (k + distUninitialized < size) {
      data[k] = bigData[k + distUninitialized];
    }
  }
  
	std::sort(&data[0], &data[LimelightDistanceIndex - distUninitialized]);

  double sum = 0;
	int counter = 0;
    for (int i = floor(size/8); i < ceil((size * 7) / 8); i++){
      sum += data[i];
      counter++;
    }
  avDist = sum/counter;
  // int distSum = 0;
  // int distUninitialized = 0;
  // for (int i = (sizeof(distHist)/doubleSize); i > 0; i--) {
  //   distHist[i] = distHist[i - 1];
  // }
  // distHist[0] = Robot::m_limelight.GetDistance();

  // for (int j = 0; j < (sizeof(distHist)/doubleSize); j++) {
  //   if (distHist[j] != 0) {
  //     distSum += distHist[j];
  //   } else {
  //     distUninitialized++;
  //   }
  // }
  // avDist = distSum/((sizeof(distHist)/doubleSize) - distUninitialized);
  
  linear_speed = -m_distance_PID.GetPID(avDist, target_distance, m_timer.Get() - previous_timer);
  rotational_speed = -m_angle_PID.GetPID(Robot::m_limelight.GetXAngle(), -kLimelightAngleOffset, m_timer.Get() - previous_timer);

  Robot::m_drivetrain.SetCurvedArcadeSpeed(linear_speed, rotational_speed);
  previous_timer = m_timer.Get();

  if (abs(Robot::m_limelight.GetDistance() - target_distance) < kDistanceFinishedThreshold) {
    debounce_incrementer++;
  } else {
    debounce_incrementer = 0;
  } 
}

bool DebouncedLimelightDistancePID::IsFinished() {
  if(debounce_incrementer >= kDebounceIncrementTik){
    return true;
  } else {
    return false;
  }
}

void DebouncedLimelightDistancePID::End() {
  Robot::m_drivetrain.SetRawSpeed(0, 0);
}

void DebouncedLimelightDistancePID::Interrupted() {
  End();
}