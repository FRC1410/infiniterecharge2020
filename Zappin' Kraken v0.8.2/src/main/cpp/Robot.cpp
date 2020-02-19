#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

OI Robot::m_oi;
Drivetrain Robot::m_drivetrain;
Intake Robot::m_intake;
IntakeFlipper Robot::m_intake_flipper;
Storage Robot::m_storage;
Shooter Robot::m_shooter;
Elevator Robot::m_elevator;
Slider Robot::m_slider;
ControlPanel Robot::m_control_panel;
Limelight Robot::m_limelight;

void Robot::RobotInit() {
  //Network table initiation
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");
  //Network table data
  target_RPM_entry = table->GetEntry("Target RPM");
  gotten_target_RPM_entry = table->GetEntry("Gotten Target RPM");
  real_RPM_entry = table->GetEntry("Real RPM");
  estimated_distance_entry = table->GetEntry("Estimated Distance");
  gyro_angle_entry = table->GetEntry("Gyro Angle");;
  intake_angle_entry = table->GetEntry("Intake Angle");
  auto_chooser_entry = table->GetEntry("Auto Chooser");
  auto_list_entry = table->GetEntry("Auto List");
  battery_voltage_entry = table->GetEntry("Battery Voltage");
  match_time_entry = table->GetEntry("Match Time");
  ll_sees_target_entry = table->GetEntry("Limelight Sees Target");
  ll_aligned_entry = table->GetEntry("Limelight Aligned");
  //PID Constant Tuning (Incomplete)
  //Probably want to use arrays(There'll be a lot of values)
  ll_angle_kP_entry = table->GetEntry("Limelight Angle kP");
  ll_angle_kI_entry = table->GetEntry("Limelight Angle kI");
  ll_angle_kD_entry = table->GetEntry("Limelight Angle kD");
  ll_distance_kP_entry = table->GetEntry("Limelight Distance kP");
  ll_distance_kI_entry = table->GetEntry("Limelight Distance kI");
  ll_distance_kD_entry = table->GetEntry("Limelight Distance kD");
  ll_angle_kP_entry.SetDouble(limelight_angle_kP);
  ll_angle_kI_entry.SetDouble(limelight_angle_kI);
  ll_angle_kD_entry.SetDouble(limelight_angle_kD);
  ll_distance_kP_entry.SetDouble(limelight_distance_kP);
  ll_distance_kI_entry.SetDouble(limelight_distance_kI);
  ll_distance_kD_entry.SetDouble(limelight_distance_kD);

  target_RPM_entry.SetDouble(kShooterRPMProfiles[2]);
  auto_chooser_entry.SetDouble(0);
  auto_list_entry.SetString(auto_list);

  Robot::m_intake_flipper.SetDesiredPosition(false);

  m_chooser.SetDefaultOption("Do nothing", nullptr);
  m_chooser.AddOption("Yeet Bot", &m_timed_drive);//reee

  //frc::SmartDashboard::PutData("Auto", &m_chooser);
  frc::SmartDashboard::PutNumber("Target RPM", kShooterRPMProfiles[2]);

  /*frc::SmartDashboard::PutNumber("Intake kP", intake_flipper_kP);
  frc::SmartDashboard::PutNumber("Intake kI", intake_flipper_kI);
  frc::SmartDashboard::PutNumber("Intake kD", intake_flipper_kD);
  
  frc::SmartDashboard::PutNumber("Debounced kP", limelight_distance_kP);
  frc::SmartDashboard::PutNumber("Debounced kI", limelight_distance_kI);
  frc::SmartDashboard::PutNumber("Debounced kD", limelight_distance_kD);*/
  m_drivetrain.SetCoastMode();
}

void Robot::RobotPeriodic() {
  match_time_entry.SetDouble(frc::DriverStation::GetInstance().GetMatchTime());
  battery_voltage_entry.SetDouble((double) frc::DriverStation::GetInstance().GetBatteryVoltage());
  gotten_target_RPM_entry.SetDouble(target_RPM_entry.GetDouble(2.54));
  real_RPM_entry.SetDouble(m_shooter.GetRPM());
  estimated_distance_entry.SetDouble(m_limelight.GetDistance());
  gyro_angle_entry.SetDouble(m_drivetrain.GetAngle());
  ll_sees_target_entry.SetBoolean(m_limelight.GetTarget());//figure out what calls alignment
  ll_distance_aligned = (abs(Robot::m_limelight.GetXAngle() + kLimelightAngleOffset) < kLimelightAngleFinishedThreshold);
  ll_angle_aligned = (abs(Robot::m_limelight.GetDistance() - Robot::m_limelight.GetNearestDistanceTarget()) < kDistanceFinishedThreshold);
  ll_aligned_entry.SetBoolean(ll_distance_aligned && ll_angle_aligned);
  
  intake_angle_entry.SetDouble(m_intake_flipper.GetAngle());
  //Getting the PID constants back(there has to be a better way!)
  ll_angle_kP_entry.GetDouble(limelight_angle_kP);
  ll_angle_kI_entry.GetDouble(limelight_angle_kI);
  ll_angle_kD_entry.GetDouble(limelight_angle_kD);
  ll_distance_kP_entry.GetDouble(limelight_distance_kP);
  ll_distance_kI_entry.GetDouble(limelight_distance_kI);
  ll_distance_kD_entry.GetDouble(limelight_distance_kD);

  frc::SmartDashboard::PutNumber("Gotten Target RPM", frc::SmartDashboard::GetNumber("Target RPM", kShooterRPMProfiles[2]));
  //frc::SmartDashboard::PutNumber("Real RPM", m_shooter.GetRPM());
  frc::SmartDashboard::PutNumber("Estimated Distance", m_limelight.GetDistance());
  //frc::SmartDashboard::PutNumber("Gyro Angle", m_drivetrain.GetAngle());
  //frc::SmartDashboard::PutNumber("Angle", m_intake_flipper.GetAngle());
  frc::SmartDashboard::PutNumber("Average Distance", m_drivetrain.GetDistance());
  frc::SmartDashboard::PutNumber("NavX Output", m_drivetrain.GetAngle());
  frc::SmartDashboard::PutNumber("X Position", m_drivetrain.GetX());
  frc::SmartDashboard::PutNumber("Zed Position", m_drivetrain.GetZ());

  frc::SmartDashboard::PutBoolean("Target Gotten", m_limelight.GetTarget());
}

void Robot::DisabledInit() {
  m_drivetrain.SetCoastMode();
  m_drivetrain.SetRawSpeed(0, 0);
  m_intake.SetSpeed(0);
  m_intake_flipper.SetSpeed(0);
  m_storage.SetSpeed(0, 0);
  m_shooter.SetSpeed(0);
  m_elevator.SetSpeed(0);
  m_slider.SetSpeed(0);
  m_control_panel.SetSpeed(0);

  m_limelight.ForceLightsOff();

  m_oi.SetDriverRumble(0);
  m_oi.SetOperatorRumble(0);
  m_oi.SetTestRumble(0);
<<<<<<< Updated upstream
=======
  frc::SmartDashboard::PutNumber("Horizontal Storage Speed", kStorageFeedShooterHorizontalSpeed);
>>>>>>> Stashed changes
  frc::SmartDashboard::PutNumber("Vertical Storage Speed", kStorageFeedShooterVerticalSpeed);
}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
  m_drivetrain.SetBrakeMode();
  frc::SmartDashboard::PutString("Auto Running?", "nope");
  chosen_auto = auto_chooser_entry.GetDouble(0);
  m_autonomous_command = autos[(int) chosen_auto];
  //m_autonomous_command = m_chooser.GetSelected();
  m_autonomous_command = autos[2];
  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Start();
  }
  m_limelight.ForceLightsOn();
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  frc::SmartDashboard::PutNumber("Target RPM", kShooterRPMProfiles[2]);
  m_drivetrain.SetBrakeMode();
  m_drivetrain.ResetGyro(0);

  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Cancel();
    m_autonomous_command = nullptr;
  }
  m_limelight.ForceLightsOn();
  m_intake_flipper.ResetAngle();
  m_intake_flipper.SetDesiredPosition(false);
  frc::SmartDashboard::PutNumber("Vertical Storage Speed", kStorageFeedShooterVerticalSpeed);
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>(); 
}
#endif