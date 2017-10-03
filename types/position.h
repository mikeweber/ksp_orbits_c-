#include "angle.h"
#include <utility>

#ifndef Position_H
#define Position_H

class Position {
  public:
    double r;
    Angle phi;
    Position();
    Position(double, Angle);
    std::pair<double, double> toCoordinates();
};

#endif
