#include <string>
#include "celestial_body.h"

#ifndef Planet_H
#define Planet_H

using namespace std;

class Planet:public CelestialBody {
    CelestialBody* parent;
  public:
    long int soi;

    Planet(CelestialBody*, string, double, long int, double, double, double, double, long int);
    long int getParentMu();
    string getParentName();
};

#endif
