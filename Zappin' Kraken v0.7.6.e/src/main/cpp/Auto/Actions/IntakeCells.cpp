#include "Auto/Actions/IntakeCells.h"
#include "Robot.h"
#include "RobotMap/Constants.h"
#include "RobotMap/Tuning.h"

IntakeCells::IntakeCells() {
  Requires(&Robot::m_intake);
  run_time = -1;
}

IntakeCells::IntakeCells(double time) {
Requires(&Robot::m_intake);
  run_time = time;
}

void IntakeCells::Initialize() {
    m_timer.Reset();
    m_timer.Start();
}

void IntakeCells::Execute() {
    if(run_time != -1 && m_timer.HasPeriodPassed(run_time) == false){
        Robot::m_intake.SetSpeed(1);
    }else if(m_timer.HasPeriodPassed(run_time) == true){
        intake_stop = true;
    }
 
    if(run_time == -1){
        Robot::m_intake.SetSpeed(1);
    }
}

bool IntakeCells::IsFinished() {
    return intake_stop;
}

void IntakeCells::End() {
    Robot::m_intake.SetSpeed(0);
}

void IntakeCells::Interrupted() {
    End();
}