#include <string>
#include "celestial_body.h"
#include "../types/coordinates.h"

#ifndef Sun_H
#define Sun_H

using namespace std;

class Sun:public CelestialBody {
  public:
    Sun(string, double, GravitationalParameter);
    Coordinates getCoordinates(Time);
};

#endif
