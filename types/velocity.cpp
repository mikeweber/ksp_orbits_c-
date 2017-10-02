#include <math.h>
#include "velocity.h"

Velocity::Velocity() {
  vel = 0.0;
  dir = 0.0;
};

Velocity::Velocity(double _vel) {
  vel = _vel;
  dir = 0.0;
};

Velocity::Velocity(double _vel, Angle _dir) {
  vel = _vel;
  dir = _dir;
};

double Velocity::x() {
  return cos(dir) * vel;
};

double Velocity::y() {
  return sin(dir) * vel;
};

