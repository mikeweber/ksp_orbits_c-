#include <string>
#include "celestial_body.h"

#ifndef Planet_H
#define Planet_H

using namespace std;

class Planet:public CelestialBody {
  public:
    Planet(string, double, long int, double, double, double, double);
};

#endif
