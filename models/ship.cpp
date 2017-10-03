#include "ship.h"

Ship::Ship() {
};

Ship::Ship(CelestialBody* _parent, string _name, Velocity _vel, Position _pos, Prograde _pro, Heading _heading, double _thrust, double _mass) {
  parent       = _parent;
  name         = _name;
  vel          = _vel;
  pos          = _pos;
  pro          = _pro;
  heading      = _heading;
  maxThrust    = _thrust;
  mass         = _mass;
  throttle     = 0.0;
  fuelConsumed = 0.0;
  fuelRate     = 0.0;
};

GravitationalParameter Ship::getParentMu() {
  return parent->mu;
};

string Ship::getParentName() {
  return parent->name;
};

void Ship::setThrottle(double _throttle) {
  if (_throttle > 1) _throttle = 1;
  if (_throttle < 0) _throttle = 0;

  throttle = _throttle;
};

double Ship::getAcceleration() {
  return getThrust() / getMass();
};

double Ship::getThrust() {
  return throttle * maxThrust;
};

void Ship::consumeFuel(double consumptionRate, double timespan) {
  fuelConsumed += consumptionRate * timespan * throttle;
};

double Ship::getMass() {
  return mass - fuelConsumed * 0.1; // 0.1kg/unit is the density of Xenon
};

void Ship::setFuelRate(double rate) {
  fuelRate = rate;
};

double Ship::getFuelRate() {
  return fuelRate;
};
