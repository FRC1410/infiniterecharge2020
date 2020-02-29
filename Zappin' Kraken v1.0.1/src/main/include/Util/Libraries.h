#pragma once

#include <frc/TimedRobot.h>

#include <frc/Joystick.h>
#include <frc/Buttons/JoystickButton.h>
#include <frc/Buttons/POVButton.h>

#include <frc/Commands/Scheduler.h>
#include <frc/Commands/Command.h>
#include <frc/Commands/CommandGroup.h>
#include <frc/Commands/Subsystem.h>

#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/SmartDashboard/SendableChooser.h>
#include <frc/Shuffleboard/Shuffleboard.h>
#include <frc/DriverStation.h>

#include <frc/Timer.h>
#include <frc/AnalogInput.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/Spark.h>

#include <NetworkTables/NetworkTable.h>
#include <NetworkTables/NetworkTableEntry.h>
#include <NetworkTables/NetworkTableInstance.h>

#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>
#include <AHRS.h>