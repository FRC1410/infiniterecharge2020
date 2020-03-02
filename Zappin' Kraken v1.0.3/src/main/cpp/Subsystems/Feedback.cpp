#include "Subsystems/Feedback.h"
#include "Commands/Looped/DisplayFeedback.h"

Feedback::Feedback() : Subsystem("ExampleSubsystem") {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  auto_move_delay = table->GetEntry("Auto Move Delay");
  auto_shoot_delay_1 = table->GetEntry("Auto Shoot Delay 1");
  auto_shoot_delay_2 = table->GetEntry("Auto Shoot Delay 2");
  ball_count = table->GetEntry("Ball Count");
  shooter_RPM = table->GetEntry("Shooter RPM");
  pressure = table->GetEntry("Pressure");
  battery_voltage = table->GetEntry("Battery Voltage");
  match_time = table->GetEntry("Match Time");

  close_target_RPM = table->GetEntry("Close Target RPM");
  near_target_RPM = table->GetEntry("Near Target RPM");
  mid_target_RPM = table->GetEntry("Mid Target RPM");
  far_target_RPM = table->GetEntry("Far Target RPM");
  close_target_angle_offset = table->GetEntry("Close Target Angle Offset");
  near_target_angle_offset = table->GetEntry("Near Target Angle Offset");
  mid_target_angle_offset = table->GetEntry("Mid Target Angle Offset");
  far_target_angle_offset = table->GetEntry("Far Target Angle Offset");

  x_position = table->GetEntry("X Position");
  z_position = table->GetEntry("Z Position");
  distance_to_target = table->GetEntry("Distance to Target");
  limelight_angle_error = table->GetEntry("Limelight Angle Error");
}

void Feedback::InitDefaultCommand() {
  SetDefaultCommand(new DisplayFeedback);
}

void Feedback::SetLEDs(double color) {
  LEDs.Set(color);
}

void Feedback::SetAligning(bool aligning_input) {
  aligning = aligning_input;
}

bool Feedback::GetAligning() {
  return aligning;
}

double Feedback::GetPressure() {
  return (50 * m_pressure.GetVoltage()) - 25; 
}

double Feedback::GetMatchTime() {
  return frc::DriverStation::GetInstance().GetMatchTime();
}

double Feedback::GetBatteryVoltage() {
  return frc::DriverStation::GetInstance().GetBatteryVoltage();
}