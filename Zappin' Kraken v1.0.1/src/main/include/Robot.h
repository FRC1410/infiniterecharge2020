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
#include "Subsystems/Feedback.h"

#include "Auto/Modes/DriveOffLine.h"
#include "Auto/Modes/DriveBackShootThree.h"
#include "Auto/Modes/ShootThreeDriveBack.h"
#include "Auto/Modes/ShootThreeDriveForwards.h"

#include "Auto/Modes/FiveBallTrench.h"
#include "Auto/Modes/SixBallTrench.h"
#include "Auto/Modes/ThreeCloseThreeMid.h"
#include "Auto/Modes/ThreeCloseThreeClose.h"

#include "Auto/Modes/BigKahunaTest.h"

class Robot : public frc::TimedRobot {
  private:
    frc::Command * m_autonomous_command = nullptr;

    frc::SendableChooser<frc::Command*> m_chooser;

    DriveOffLine m_drive_off_line;
    DriveBackShootThree m_drive_back_shoot_three;
    ShootThreeDriveBack m_shoot_three_drive_back;
    ShootThreeDriveForwards m_shoot_three_drive_forwards;

    FiveBallTrench m_five_ball_trench;
    SixBallTrench m_six_ball_trench;
    ThreeCloseThreeMid m_three_close_three_mid;
    ThreeCloseThreeClose m_three_close_three_close;
    
    BigKahunaTest m_kahuna;

    bool ll_distance_aligned, ll_angle_aligned;
    std::string auto_list = "Nothing,3+3 Close,3+3 Mid,6 Trench,5 Trench,3 go back,3 go forwards,Go back + 3,Go back";
    frc::Command* autos[10] = {nullptr, &m_three_close_three_close, &m_three_close_three_mid, &m_six_ball_trench, &m_five_ball_trench, &m_shoot_three_drive_back, &m_shoot_three_drive_forwards, &m_drive_back_shoot_three, &m_drive_off_line, &m_kahuna};

    nt::NetworkTableEntry auto_selector_entry, auto_list_entry;

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
    static Feedback m_feedback;

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