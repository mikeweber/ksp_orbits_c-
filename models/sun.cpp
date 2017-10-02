#include <string>
#include "sun.h"
#include "../types/position.h"

using namespace std;

Sun::Sun(string body_name, double body_radius, long int body_mu) {
  Position* pos = new Position(0.0, 0.0);
  init(body_name, body_radius, body_mu, 0.0, pos, 0.0, 0.0, 0.0);
};
