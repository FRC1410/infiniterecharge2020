#include "Util/GreenScreen.h"
#include "RobotMap/Tuning.h"
#include "RobotMap/Constants.h"

GreenScreen::GreenScreen() : Subsystem("ExampleSubsystem") {
  //Initializing a Network Table 
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");
  //Initializing Network Table Entries
  real_RPM_entry = table->GetEntry("Real RPM");
  estimated_distance_entry = table->GetEntry("Estimated Distance");
  gyro_angle_entry = table->GetEntry("Gyro Angle");
  battery_voltage_entry = table->GetEntry("Battery Voltage");
  match_time_entry = table->GetEntry("Match Time");
  //Limelight
  ll_sees_target_entry = table->GetEntry("Limelight Sees Target");
  ll_aligned_entry = table->GetEntry("Limelight Aligned");
  angle_error_entry = table->GetEntry("Angle Error");
  ll_distance_kP = table->GetEntry("Limelight Distance kP");
  ll_distance_kI = table->GetEntry("Limelight Distance kI");
  ll_distance_kD = table->GetEntry("Limelight Distance kD");
  ll_angle_kP = table->GetEntry("Limelight Angle kP");
  ll_angle_kI = table->GetEntry("Limelight Angle kI");
  ll_angle_kD = table->GetEntry("Limelight Angle kD");
  ll_distance_kP.SetDouble(limelight_distance_kP);
  ll_distance_kI.SetDouble(limelight_distance_kI);
  ll_distance_kD.SetDouble(limelight_distance_kD);
  ll_angle_kP.SetDouble(limelight_angle_kP);
  ll_angle_kI.SetDouble(limelight_angle_kI);
  ll_angle_kD.SetDouble(limelight_angle_kD);
  //Auto
  auto_chooser_entry = table->GetEntry("Auto Chooser");
  auto_list_entry = table->GetEntry("Auto List");
  //Storage
  vertical_power_entry = table->GetEntry("Vertical Power");
  ball_count_entry = table->GetEntry("Ball Count");
  //Shooter
  shooter_speed_entry = table->GetEntry("Shooter Speed");
  target_RPM_entry = table->GetEntry("Target RPM");
  shooter_kP_entry = table->GetEntry("Shooter kP");
  shooter_kI_entry = table->GetEntry("Shooter kI");
  shooter_kD_entry = table->GetEntry("Shooter kD");
  shooter_kF_entry = table->GetEntry("Shooter kF");
  shooter_kP_entry.SetDouble(shooter_kP);
  shooter_kI_entry.SetDouble(shooter_kI);
  shooter_kD_entry.SetDouble(shooter_kD);
  shooter_kF_entry.SetDouble(shooter_kF);
  target_RPM_entry.SetDouble(kShooterRPMProfiles[2]);
  //Drivetrain
  speed_entry = table->GetEntry("Speed");
  time_entry = table->GetEntry("Time");
  yeet_entry = table->GetEntry("yeet");
  time_entry.SetDouble(kTimedDriveDefaultTime);
	speed_entry.SetDouble(kTimedDriveDefaultSpeed);
  dt_distance_kP_entry = table->GetEntry("Drivetrain Distance kP");
  dt_distance_kI_entry = table->GetEntry("Drivetrain Distance kI");
  dt_distance_kD_entry = table->GetEntry("Drivetrain Distance kD");
  dt_distance_kP_entry.SetDouble(drivetrain_distance_kP);
  dt_distance_kI_entry.SetDouble(drivetrain_distance_kI);
  dt_distance_kD_entry.SetDouble(drivetrain_distance_kD);
  dt_angle_kP_entry = table->GetEntry("Drivetrain Angle kP");
  dt_angle_kI_entry = table->GetEntry("Drivetrain Angle kI");
  dt_angle_kD_entry = table->GetEntry("Drivetrain Angle kD");
  dt_angle_kP_entry.SetDouble(drivetrain_angle_kP);
  dt_angle_kI_entry.SetDouble(drivetrain_angle_kI);
  dt_angle_kD_entry.SetDouble(drivetrain_angle_kD);
  //Boost
  boost_entry = table->GetEntry("Boost");
  //Intake Flipper
  if_kP_entry = table->GetEntry("Intake Flipper kP");
  if_kI_entry = table->GetEntry("Intake Flipper kI");
  if_kD_entry = table->GetEntry("Intake Flipper kD");
  if_kP_entry.SetDouble(intake_flipper_kP);
  if_kI_entry.SetDouble(intake_flipper_kI);
  if_kD_entry.SetDouble(intake_flipper_kD);
  //Auto Offset
  x_offset_kP_entry = table->GetEntry("Auto X Offset kP");
  x_offset_kP_entry.SetDouble(x_offset_kP);
  //Logger
  log_entry = table->GetEntry("Logger");
  //Delay
  shoot_delay_entry = table->GetEntry("Shoot Delay");
  move_delay_entry = table->GetEntry("Move Delay");
  get_move_delay = move_delay_entry.GetDouble(0);
  get_shoot_delay = shoot_delay_entry.GetDouble(0);
}

void GreenScreen::InitDefaultCommand() {}