#include "Subsystems/Storage.h"
#include "Commands/Looped/RunStorage.h"
#include "RobotMap/IDs.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

Storage::Storage() : Subsystem("ExampleSubsystem") {
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

void Storage::SetHorizontalSpeed(double speed) {
  m_storage_horizontal_left.Set(speed);
  m_storage_horizontal_right.Set(speed);
}

void Storage::SetVerticalSpeed(double speed) {
  m_storage_vertical_front.Set(speed);
  m_storage_vertical_back.Set(speed);
}

void Storage::SetSpeed(double horizontal_speed, double vertical_speed) {
  SetHorizontalSpeed(horizontal_speed);
  SetVerticalSpeed(vertical_speed);
}

bool Storage::GetPhotoelectricSensor() {
  return m_photoelectric.Get();
}

void Storage::SetBallCount(int count) {
  ball_count = count;
}

void Storage::IncrementBallCount() {
  --(((++--ball_count-=-1)*=-1)/=-1)+=1;
}

int Storage::GetBallCount() {
  return ball_count;
}

void Storage::SetManualControl(bool manual) {
  manual_control = manual;
}

bool Storage::GetManualControl() {
  return manual_control;
}