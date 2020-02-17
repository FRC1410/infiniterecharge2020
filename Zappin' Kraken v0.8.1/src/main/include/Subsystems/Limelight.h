#pragma once

#include "Util/Libraries.h"

class Limelight : public frc::Subsystem {
  private:
    std::shared_ptr<NetworkTable> limelight_table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double vertical_resolution = 720, nearest, raw_distance_calculation;

  public:
    Limelight();
    void InitDefaultCommand() override;
    void ForceLightsOn();
    void ForceLightsOff();
    bool GetTarget();
    double GetXAngle();
    double GetDistance();
    double GetNearestDistanceTarget();
    double GetNearestRPMProfile();
};