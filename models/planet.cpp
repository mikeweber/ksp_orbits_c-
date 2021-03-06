#include <string>
#include "planet.h"

using namespace std;

Planet::Planet(CelestialBody* _parent, string body_name, double body_radius, GravitationalParameter body_mu, double semimajor_axis, Angle anomaly, Angle body_arg_of_pe, double eccentricity, long int _soi) {
  parent = _parent;
  soi    = _soi;

  double prograde = TAU / 4;
  Position pos = Position(semimajor_axis, anomaly);
  init(body_name, body_radius, body_mu, semimajor_axis, pos, body_arg_of_pe, eccentricity, prograde);
};

Coordinates Planet::getCoordinates(Time t) {
  return getLocalCoordinates(t) + parent->getCoordinates(t);
};

