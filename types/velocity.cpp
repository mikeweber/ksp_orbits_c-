#include "velocity.h"

Velocity::Velocity() {
  vel = 0.0;
  dir = 0.0;
  x = vel;
  y = 0.0;
};

Velocity::Velocity(double _vel) {
  vel = _vel;
  dir = 0.0;
};

Velocity::Velocity(double _vel, Angle _dir) {
  vel = _vel;
  dir = _dir;
  x = dir.cos() * vel;
  y = dir.sin() * vel;
};

Velocity::Velocity(double _x, double _y) {
  x = _x;
  y = _y;
  vel = sqrt(x * x + y * y);
  dir = Angle(atan2(y, x));
};

double Velocity::getX() {
  return x;
};

double Velocity::getY() {
  return y;
};

