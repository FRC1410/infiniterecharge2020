#pragma once

#include "Util/Libraries.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

class Limelight : public frc::Subsystem {
  private:
    std::shared_ptr<NetworkTable> limelight_table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double raw_distance_calculation;
    double RPM_profiles[(int) (sizeof(kShooterDistanceProfiles) / kDoubleSize)];
    double angle_offsets[(int) (sizeof(kShooterDistanceProfiles) / kDoubleSize)];
    int nearest_profile, last_profile = -1;
    bool disabled;

  public:
    Limelight();
    void InitDefaultCommand() override;

    void TurnOnLights();
    void TurnOffLights();
    bool GetTarget();
    double GetXAngle();
    double GetDistance();

    int GetNearestProfile();
    double GetNearestDistanceTarget();
    double GetNearestRPMProfile();
    double GetNearestAngleOffset();

    void SetLastProfile();
    void IncrementLastRPMProfile(double increment);
    void IncrementLastAngleOffset(double increment);
    double * GetRPMProfiles();
    double * GetAngleOffsets();
};