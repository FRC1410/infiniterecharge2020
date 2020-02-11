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

class Robot : public frc::TimedRobot {
  private:
    frc::Command * m_autonomous_command = nullptr;
    frc::Command * m_moveforward = nullptr;
    frc::Command * m_auto = nullptr;

    frc::SendableChooser<frc::Command*> m_chooser;

    TimedDrive m_timed_drive;

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