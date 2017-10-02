#include "angle.h"

#ifndef Position_H
#define Position_H

class Position {
  public:
    double r;
    Angle phi;
    Position();
    Position(double, Angle);
};

#endif
