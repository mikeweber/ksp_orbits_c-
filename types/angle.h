#include "../utils/clamp_radians.h"

#ifndef Angle_H
#define Angle_H

class Angle {
  public:
    double dir;
    Angle();
    Angle(double);
    Angle(double, double);
    virtual double getRadians();
    operator double() { return getRadians(); };
    Angle operator+(Angle);
    double sin();
    double cos();
};

#endif
