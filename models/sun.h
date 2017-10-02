#include <string>
#include "celestial_body.h"

#ifndef Sun_H
#define Sun_H

using namespace std;

class Sun:public CelestialBody {
  public:
    Sun(string, double, GravitationalParameter);
};

#endif
