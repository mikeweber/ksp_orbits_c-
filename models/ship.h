#include <string>
#include "celestial_body.h"
#include "../types/velocity.h"
#include "../types/prograde.h"
#include "../types/heading.h"

#ifndef Ship_H
#define Ship_H

using namespace std;

class Ship:public CelestialBody {
    CelestialBody* parent;
  public:
    Ship();
    Ship(CelestialBody*, string, Velocity, Position, Prograde, Heading);
    GravitationalParameter getParentMu();
    string getParentName();

  private:
    Velocity vel;
    Prograde pro;
    Heading heading;
};

#endif
