#include "angle.h"
#include "velocity.h"

#ifndef Acceleration_H
#define Acceleration_H

class Acceleration {
  public:
    Acceleration();
    Acceleration(double, Angle);
    Acceleration(double, double);
    Acceleration operator+(Acceleration);
    Acceleration operator*(double);
    Velocity toVelocity(double);
    double getX();
    double getY();

  private:
    Angle angle;
    double x;
    double y;
};

#endif
