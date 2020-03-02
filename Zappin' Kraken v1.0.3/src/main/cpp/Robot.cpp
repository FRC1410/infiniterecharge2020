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
Feedback Robot::m_feedback;

void Robot::RobotInit() {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  auto_chooser_entry = table->GetEntry("Auto Chooser");
  auto_list_entry = table->GetEntry("Auto List");
  auto_chooser_entry.SetDouble(0);
  auto_list_entry.SetString(auto_list);

  Robot::m_intake_flipper.SetDesiredPosition(kIntakeFlipperUp);

  m_intake_flipper.ResetAngle();
  m_storage.SetManualControl(false);
}

void Robot::RobotPeriodic() {
  m_drivetrain.IncrementXZ();

  m_feedback.ball_count.SetDouble(m_storage.GetBallCount());
  m_feedback.shooter_RPM.SetDouble(m_shooter.GetRPM());
  m_feedback.pressure.SetDouble(m_feedback.GetPressure());
  m_feedback.battery_voltage.SetDouble(m_feedback.GetBatteryVoltage());
  m_feedback.match_time.SetDouble(m_feedback.GetMatchTime());

  m_feedback.close_target_RPM.SetDouble(m_limelight.GetRPMProfiles()[0]);
  m_feedback.near_target_RPM.SetDouble(m_limelight.GetRPMProfiles()[1]);
  m_feedback.mid_target_RPM.SetDouble(m_limelight.GetRPMProfiles()[2]);
  m_feedback.far_target_RPM.SetDouble(m_limelight.GetRPMProfiles()[3]);
  m_feedback.close_target_angle_offset.SetDouble(m_limelight.GetAngleOffsets()[0]);
  m_feedback.near_target_angle_offset.SetDouble(m_limelight.GetAngleOffsets()[1]);
  m_feedback.mid_target_angle_offset.SetDouble(m_limelight.GetAngleOffsets()[2]);
  m_feedback.far_target_angle_offset.SetDouble(m_limelight.GetAngleOffsets()[3]);

  m_feedback.x_position.SetDouble(m_drivetrain.GetX());
  m_feedback.z_position.SetDouble(m_drivetrain.GetZ());
  m_feedback.distance_to_target.SetDouble(m_limelight.GetDistance());
  m_feedback.limelight_angle_error.SetDouble(m_limelight.GetXAngle() + m_limelight.GetNearestAngleOffset());
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

  m_limelight.TurnOffLights();

  m_oi.SetDriverRumble(0);
  m_oi.SetOperatorRumble(0);
  m_oi.SetTestRumble(0);
}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
  m_drivetrain.ResetEncoders();
  m_drivetrain.ResetGyro(0);
  m_drivetrain.SetXZ(0, 0);

  m_intake_flipper.ResetAngle();
  m_intake_flipper.SetDesiredPosition(kIntakeFlipperUp);

  m_storage.SetBallCount(3);
  m_storage.SetManualControl(false);
  m_storage.SetAutonomouslyRunning(false);
  m_storage.SetShooting(false);
  m_elevator.SetBrake(true);

  m_limelight.TurnOnLights();

  m_autonomous_command = autos[(int) auto_chooser_entry.GetDouble(0)];

  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Start();
  }
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  m_storage.SetShooting(false);
  m_storage.SetAutonomouslyRunning(false);
  m_elevator.SetBrake(true);

  if (m_autonomous_command != nullptr) {
    m_autonomous_command->Cancel();
    m_autonomous_command = nullptr;
  }
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