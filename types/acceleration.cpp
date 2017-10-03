#include "acceleration.h"

Acceleration::Acceleration() {
  x = 0.0;
  y = 0.0;
};

Acceleration::Acceleration(double accel, Angle _angle) {
  angle = _angle;
  x     = accel * angle.cos();
  y     = accel * angle.sin();
};

Acceleration::Acceleration(double _x, double _y) {
  x = _x;
  y = _y;
  angle = Angle(x, y);
};

Acceleration Acceleration::operator+(Acceleration acc) {
  return Acceleration(getX() + acc.getX(), getY() + acc.getY());
};

Acceleration Acceleration::operator*(double dt) {
  return Acceleration(getX() *dt, getY() * dt);
};

Velocity Acceleration::toVelocity(double dt) {
  return Velocity(getX() * dt / 2, getY() * dt / 2);
};

double Acceleration::getX() {
  return x;
};

double Acceleration::getY() {
  return y;
};

// Hack hackity hack
Velocity Velocity::operator+(Acceleration a) {
  return Velocity(getX() + a.getX(), getY() + a.getY());
};

