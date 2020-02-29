#include "Subsystems/Limelight.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

#include "Commands/Looped/DisplayFeedback.h"

Limelight::Limelight() : Subsystem("ExampleSubsystem") {
  for (int x = 0; x < (sizeof(kShooterDistanceProfiles) / kDoubleSize); x++) {
    RPM_profiles[x] = kShooterRPMProfiles[x];
    angle_offsets[x] = kShooterAngleOffsets[x];
  }
}

void Limelight::InitDefaultCommand() {}

void Limelight::TurnOnLights() {
  limelight_table->PutNumber("ledMode", 3);
}

void Limelight::TurnOffLights() {
  limelight_table->PutNumber("ledMode", 0);
}

bool Limelight::GetTarget() {
  return limelight_table->GetNumber("tv", 0);
}

double Limelight::GetXAngle() {
  return limelight_table->GetNumber("tx", 0);
}

double Limelight::GetDistance() {
  raw_distance_calculation = (kTargetHeight * kLimelightVerticalResolution) / (2 * tan(kLimelightVerticalFOV / 2) * limelight_table->GetNumber("tshort", 0) * cos(GetXAngle() * pi/180));
  return (raw_distance_calculation * kLimelightDistanceMultiplier) - kLimelightDistanceOffset;
}

int Limelight::GetNearestProfile() {
  nearest_profile = 0;
  for (int x = 0; x < (sizeof(kShooterDistanceProfiles) / kDoubleSize); x++) {
    if (abs(GetDistance() - kShooterDistanceProfiles[x]) < abs(GetDistance() - kShooterDistanceProfiles[nearest_profile])) {
      nearest_profile = x;
    }
  }
  return nearest_profile;
}

double Limelight::GetNearestDistanceTarget() {
  return kShooterDistanceProfiles[GetNearestProfile()];
}

double Limelight::GetNearestRPMProfile() {
  return RPM_profiles[GetNearestProfile()];
}

double Limelight::GetNearestAngleOffset() {
  return angle_offsets[GetNearestProfile()];
}

void Limelight::SetLastProfile() {
  last_profile = GetNearestProfile();
}

void Limelight::IncrementLastRPMProfile(double increment) {
  if (last_profile >= 0) {
    RPM_profiles[last_profile] += increment;
  }
}

void Limelight::IncrementLastAngleOffset(double increment) {
  if (last_profile >= 0) {
    angle_offsets[last_profile] += increment;
  }
}

double * Limelight::GetRPMProfiles() {
  return RPM_profiles;
}

double * Limelight::GetAngleOffsets() {
  return angle_offsets;
}