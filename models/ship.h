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
    Ship(CelestialBody*, string, Velocity, Position, Prograde, Heading, double, double);
    GravitationalParameter getParentMu();
    string getParentName();
    void setThrottle(double);
    double getAcceleration();
    double getThrust();
    void consumeFuel(double, double);
    double getMass();
    void setFuelRate(double);
    double getFuelRate();

  private:
    Velocity vel;
    Prograde pro;
    Heading heading;
    double maxThrust;
    double mass;
    double throttle;
    double fuelConsumed;
    double fuelRate;
};

#endif
