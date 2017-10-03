#include <math.h>
#include "angle.h"

Angle::Angle() {
  dir = 0;
};

Angle::Angle(double _dir) {
  dir = _dir;
};

Angle::Angle(double x, double y) {
  dir = atan2(y, x);
}

double Angle::getRadians() {
  return clampRadians(dir);
};

double Angle::sin() {
  return ::sin(dir);
};

double Angle::cos() {
  return ::cos(dir);
};

Angle Angle::operator+(Angle phi) {
  return Angle(dir + phi);
};
