#include <string>
#include "planet.h"
#include "../tau.h"

using namespace std;

Planet::Planet(string body_name, double body_radius, long int body_mu, double semimajor_axis, double anomaly, double body_arg_of_pe, double eccentricity) {
  double prograde = TAU / 4;
  init(body_name, body_radius, body_mu, semimajor_axis, body_arg_of_pe, eccentricity, prograde);
};
