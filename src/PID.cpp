#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    isInit=false;
}

PID::~PID() {}

void PID::Init(double dt, double Kp, double Ki, double Kd)
{
    _dt = dt;
    // Init factors
    PID::Kp = Kp/1000;
    PID::Ki = Ki/1000;
    PID::Kd = Kd/1000;

    // Init errors
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    pre_error=0.0;
    isInit=true;
}

bool PID::isInitialized()
{
    return isInit;
}

void PID::Update(double expectedVal, double realVal)
{
    // Error
    double error = realVal -expectedVal;

    // Calculate d value
    d_error = (error - pre_error) / _dt;

    // P Error value
    p_error=error;

    // I Error
    i_error += error * _dt;
    
    // Update previous error
    pre_error = error;
}


double PID::P_Error()
{
    return Kp * p_error;
}

double PID::I_Error()
{
    return Ki * i_error;
}

double PID::D_Error()
{
    return Kd * d_error;
}

double PID::TotalError()
{
    return PID::P_Error() + PID::I_Error() + PID::D_Error();
    // return -Kp * p_error - Kd * d_error - Ki * i_error;
}