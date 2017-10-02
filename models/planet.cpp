#include <iostream>
#include <string>
#include "planet.h"
#include "celestial_body.h"
#include "../types/position.h"
#include "../utils/tau.h"

using namespace std;

Planet::Planet(CelestialBody* _parent, string body_name, double body_radius, GravitationalParameter body_mu, double semimajor_axis, double anomaly, double body_arg_of_pe, double eccentricity, long int _soi) {
  parent = _parent;
  soi    = _soi;

  double prograde = TAU / 4;
  Position* pos = new Position(semimajor_axis, anomaly);
  init(body_name, body_radius, body_mu, semimajor_axis, pos, body_arg_of_pe, eccentricity, prograde);
};

GravitationalParameter Planet::getParentMu() {
  return parent->mu;
};

string Planet::getParentName() {
  return parent->name;
};
