#include "../utils/clamp_radians.h"

#ifndef Angle_H
#define Angle_H

class Angle {
  public:
    double dir;
    Angle();
    Angle(double _dir);
    virtual double getRadians();
    operator double() {
      return getRadians();
    };
};

#endif
