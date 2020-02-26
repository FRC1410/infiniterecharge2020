#include "Subsystems/Limelight.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Limelight::Limelight() : Subsystem("ExampleSubsystem") {}

void Limelight::InitDefaultCommand() {}

void Limelight::ForceLightsOn() {
  limelight_table->PutNumber("ledMode", 3);
}

void Limelight::ForceLightsOff() {
  limelight_table->PutNumber("ledMode", 1);
}

bool Limelight::GetTarget() {
  return limelight_table->GetBoolean("tv", false);
}

double Limelight::GetXAngle() {
  return limelight_table->GetNumber("tx", 0);
}

double Limelight::GetDistance() {
  return ((kLimelightDistanceModifier * kTargetHeight * vertical_resolution) / (2 * tan(kLimelightVerticalFOV / 2) * limelight_table->GetNumber("tshort", 0) * cos(GetXAngle() * pi/180)));
}

double Limelight::GetNearestDistanceTarget() {
  nearest = kShooterDistanceProfiles[0];
  for (int x = 1; x < (sizeof(kShooterDistanceProfiles) / 8); x++) {
    if (abs(GetDistance() - kShooterDistanceProfiles[x]) < abs(GetDistance() - nearest)) {
      nearest = kShooterDistanceProfiles[x];
    }
  }
  return nearest;
}

double Limelight::GetNearestRPMProfile() {
  GetNearestDistanceTarget();
  for (int x = 0; x < (sizeof(kShooterRPMProfiles) / 8); x++) {
    if (nearest == kShooterDistanceProfiles[x]) {
      return kShooterRPMProfiles[x];
    }
  }
}