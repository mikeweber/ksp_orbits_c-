#include "angle.h"

#ifndef Velocity_H
#define Velocity_H

class Acceleration;

class Velocity {
  public:
    Velocity();
    Velocity(double);
    Velocity(double, Angle);
    Velocity(double, double);
    operator double() { return vel; };
    Velocity operator+(Acceleration);
    double getX();
    double getY();

  private:
    double vel;
    Angle dir;
    double x;
    double y;
};

#endif
