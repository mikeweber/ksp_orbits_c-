#include <string>
#include "celestial_body.h"
#include "../types/velocity.h"
#include "../types/coordinates.h"
#include "../types/heading.h"
#include "../types/time.h"
#include "../types/acceleration.h"

#ifndef Ship_H
#define Ship_H

using namespace std;

class Ship:public CelestialBody {
  CelestialBody* parent;
  Velocity vel;
  Heading heading;
  double maxThrust;
  double mass;
  double throttle;
  double fuelConsumed;
  double fuelRate;

  public:
    Ship();
    Ship(CelestialBody*, string, Velocity, Position, Heading, double, double);
    GravitationalParameter getParentMu();
    string getParentName();
    void step(Time, double);
    Coordinates getCoordinates(Time);
    void setThrottle(double);
    Acceleration getAcceleration();
    double getThrust();
    void consumeFuel(double, double);
    double getMass();
    void setFuelRate(double);
    double getFuelRate();
    void updateInitialMeanAnomaly(Time);
};

#endif
