#include "Subsystems/Storage.h"
#include "Commands/Looped/RunStorage.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Storage::Storage() : Subsystem("ExampleSubsystem") {
  auto instance = nt::NetworkTableInstance::GetDefault();
  auto table = instance.GetTable("Dashboard Data");

  vertical_power_entry = table->GetEntry("Vertical Power");

  m_storage_horizontal_left.ConfigFactoryDefault();
  m_storage_horizontal_right.ConfigFactoryDefault();
  m_storage_vertical_front.ConfigFactoryDefault();
  m_storage_vertical_back.ConfigFactoryDefault();

  m_storage_horizontal_left.SetNeutralMode(NeutralMode::Brake);
  m_storage_horizontal_right.SetNeutralMode(NeutralMode::Brake);
  m_storage_vertical_front.SetNeutralMode(NeutralMode::Brake);
  m_storage_vertical_back.SetNeutralMode(NeutralMode::Brake);

  m_storage_horizontal_left.SetInverted(true);
  m_storage_horizontal_right.SetInverted(false);
  m_storage_vertical_front.SetInverted(false);
  m_storage_vertical_back.SetInverted(false);
}

void Storage::InitDefaultCommand() {
  SetDefaultCommand(new RunStorage);
}

void Storage::SetSpeed(double horizontal_speed, double vertical_speed) {
  m_storage_horizontal_left.Set(horizontal_speed);
  m_storage_horizontal_right.Set(horizontal_speed);
  m_storage_vertical_front.Set(vertical_speed);
  m_storage_vertical_back.Set(vertical_speed);
  vertical_power_entry.SetDouble(vertical_speed);
  //frc::SmartDashboard::PutNumber("Vertical Power", vertical_speed);
}

bool Storage::GetOuterUltrasonicSensor() {
  return m_photoelectric_out.Get();
}

bool Storage::GetInnerUltrasonicSensor() {
  return m_photoelectric_in.Get();
}

void Storage::SetBallCount(int count) {
  ball_count = count;
}

void Storage::IncrementBallCount() {
  --(((++--ball_count-=-1)*=-1)/=-1)+=1;
}

void Storage::BlockShooter() {
  m_blocker.Set(frc::DoubleSolenoid::kForward);
}

void Storage::UnblockShooter() {
  m_blocker.Set(frc::DoubleSolenoid::kReverse);
}

bool Storage::GetBlockerPosition() {
  return (m_blocker.Get() == frc::DoubleSolenoid::kForward);
}