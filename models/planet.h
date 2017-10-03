#include <string>
#include "celestial_body.h"
#include "../types/coordinates.h"
#include "../types/position.h"
#include "../types/time.h"
#include "../utils/tau.h"

#ifndef Planet_H
#define Planet_H

using namespace std;

class Planet:public CelestialBody {
    CelestialBody* parent;
  public:
    long int soi;

    Planet(CelestialBody*, string, double, GravitationalParameter, double, Angle, Angle, double, long int);
    GravitationalParameter getParentMu();
    string getParentName();
    Coordinates getCoordinates(Time);
};

#endif
