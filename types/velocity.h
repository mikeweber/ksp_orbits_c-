#include "angle.h"
#ifndef Velocity_H
#define Velocity_H

class Velocity {
  public:
    Velocity();
    Velocity(double);
    Velocity(double, Angle);
    operator double() {
      return vel;
    };
    double x();
    double y();

  private:
    double vel;
    Angle dir;
};

#endif
