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

  Robot::m_intake_flipper.SetDesiredPosition(false);

  m_chooser.SetDefaultOption("Do nothing", nullptr);
  m_chooser.AddOption("Yeet Bot", &m_timed_drive);//reee

  frc::SmartDashboard::PutData("Auto", &m_chooser);
  frc::SmartDashboard::PutNumber("Target RPM", kShooterRPMProfiles[2]);
}

void Robot::RobotPeriodic() {
  m_drivetrain.IncrementXZ();
  target_RPM_entry.SetDouble(kShooterRPMProfiles[2]);
  gotten_target_RPM_entry.SetDouble(1);
  real_RPM_entry.SetDouble(m_shooter.GetRPM());
  estimated_distance_entry.SetDouble(m_limelight.GetDistance());
  
  //frc::SmartDashboard::PutNumber("Gotten Target RPM", frc::SmartDashboard::GetNumber("Target RPM", kShooterRPMProfiles[2]));
  //frc::SmartDashboard::PutNumber("Real RPM", m_shooter.GetRPM());
  //frc::SmartDashboard::PutNumber("Estimated Distance", m_limelight.GetDistance());
  //frc::SmartDashboard::PutNumber("Gyro Angle", m_drivetrain.GetAngle());
  
}

void Robot::DisabledInit() {
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
}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
  m_autonomous_command = m_chooser.GetSelected();
  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Start();
  }
  m_limelight.ForceLightsOn();
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  m_drivetrain.ResetGyro(0);

  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Cancel();
    m_autonomous_command = nullptr;
  }
  m_limelight.ForceLightsOn();
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