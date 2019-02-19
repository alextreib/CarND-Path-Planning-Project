#ifndef PID_H
#define PID_H

#include <algorithm>

class PID
{
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  /*
  * Errors
  */
  double pre_error;
  double _dt;
  bool isInit;
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double dt, double Kp, double Ki=0.0, double Kd=0.0);

bool isInitialized();
  /*
  * Update the PID error variables given cross track error.
  */
  void Update(double expectedVal, double realVal);

  /*
  * Calculate the total PID error.
  */

  double P_Error();

  double I_Error();

  double D_Error();

  double TotalError();

};

#endif /* PID_H */
