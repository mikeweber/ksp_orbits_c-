#include "velocity.h"
#include "position.h"

#ifndef Coordinates_H
#define Coordinates_H

class Coordinates {
  public:
    double x;
    double y;
    Coordinates();
    Coordinates(double, double);
    Coordinates operator+(Velocity);
    Coordinates operator+(Coordinates);
    Position toPosition();
};

#endif
