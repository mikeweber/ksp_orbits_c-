#include <string>
#include "celestial_body.h"

using namespace std;

CelestialBody::CelestialBody() {};

CelestialBody::CelestialBody(string body_name, double body_radius, long int body_mu, double body_v, double semimajor_axis, double body_arg_of_pe, double eccentricity, double prograde) {
  init(body_name, body_radius, body_mu, semimajor_axis, body_arg_of_pe, eccentricity, prograde);
  v   = body_v;
};

CelestialBody::init(string body_name, double body_radius, long int body_mu, double semimajor_axis, double body_arg_of_pe, double eccentricity, double prograde) {
  name      = body_name;
  radius    = body_radius;
  mu        = body_mu;
  a         = semimajor_axis;
  arg_of_pe = body_arg_of_pe;
  e         = eccentricity;
};

CelestialBody::~CelestialBody() {
};

Position* CelestialBody::getPositionAtTime(Time t) {
  return new Position();
};

