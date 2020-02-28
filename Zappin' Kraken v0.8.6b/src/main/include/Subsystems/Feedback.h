#pragma once

#include "Util/Libraries.h"
#include "RobotMap/IDs.h"

class Feedback : public frc::Subsystem {
  private:
    frc::Spark LEDs{kLEDController};
    frc::AnalogInput m_pressure{kPressureSensor};
    bool aligning;

  public:
    nt::NetworkTableEntry auto_move_delay, auto_shoot_delay_1, auto_shoot_delay_2;
    nt::NetworkTableEntry ball_count, shooter_RPM;
    nt::NetworkTableEntry pressure, battery_voltage, match_time;

    nt::NetworkTableEntry x_position, z_position;
    nt::NetworkTableEntry distance_to_target, limelight_angle_error;
    nt::NetworkTableEntry super_close_target_RPM, close_target_RPM, mid_target_RPM, far_target_RPM;

    Feedback();
    void InitDefaultCommand() override;
    void SetAligning(bool aligning_input);
    bool GetAligning();
    double GetPressure();
    double GetMatchTime();
    double GetBatteryVoltage();
};