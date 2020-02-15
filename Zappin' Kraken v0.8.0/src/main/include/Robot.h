#pragma once

#include "Util/Libraries.h"

#include "OI.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/IntakeFlipper.h"
#include "Subsystems/Storage.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Slider.h"
#include "Subsystems/ControlPanel.h"
#include "Subsystems/Limelight.h"

#include "Auto/Modes/TimedDrive.h"
#include <string.h>

class Robot : public frc::TimedRobot {
  private:
    frc::Command * m_autonomous_command = nullptr, * m_moveforward = nullptr, * m_auto = nullptr;

    frc::SendableChooser<frc::Command*> m_chooser;

    TimedDrive m_timed_drive;

    nt::NetworkTableEntry target_RPM_entry, gotten_target_RPM_entry, real_RPM_entry;
    nt::NetworkTableEntry estimated_distance_entry;
    nt::NetworkTableEntry gyro_angle_entry;
    nt::NetworkTableEntry intake_angle_entry;
    nt::NetworkTableEntry auto_chooser_entry, auto_list_entry;
    nt::NetworkTableEntry battery_voltage_entry, match_time_entry;
    nt::NetworkTableEntry ll_aligned_entry, ll_sees_target_entry;

    nt::NetworkTableEntry ll_angle_kP_entry, ll_angle_kI_entry, ll_angle_kD_entry;
    nt::NetworkTableEntry ll_distance_kP_entry, ll_distance_kI_entry, ll_distance_kD_entry;
    
    double chosen_auto;
    bool ll_distance_aligned, ll_angle_aligned;
    std::string auto_list = "Do Nothing,Yeet Bot";
    frc::Command* autos[2] = {nullptr, &m_timed_drive};

  public:
    static OI m_oi;
    static Controller m_controller;
    
    static Drivetrain m_drivetrain;
    static Intake m_intake;
    static IntakeFlipper m_intake_flipper;
    static Storage m_storage;
    static Shooter m_shooter;
    static Elevator m_elevator;
    static Slider m_slider;
    static ControlPanel m_control_panel;
    static Limelight m_limelight;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
};