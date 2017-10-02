#include <string>
#include "celestial_body.h"

#ifndef Planet_H
#define Planet_H

using namespace std;

class Planet:public CelestialBody {
    CelestialBody* parent;
  public:
    long int soi;

    Planet(CelestialBody*, string, double, GravitationalParameter, double, double, double, double, long int);
    GravitationalParameter getParentMu();
    string getParentName();
};

#endif
