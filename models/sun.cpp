#include <string>
#include "sun.h"
#include "../types/position.h"
#include "../types/gravitational_parameter.h"

using namespace std;

Sun::Sun(string body_name, double body_radius, GravitationalParameter body_mu) {
  Position* pos = new Position(0.0, 0.0);
  init(body_name, body_radius, body_mu, 0.0, pos, 0.0, 0.0, 0.0);
};

Coordinates Sun::getCoordinates(Time t) {
  return Coordinates(0.0, 0.0);
};
