#include "angle.h"

Angle::Angle() {
  dir = 0;
};

Angle::Angle(double _dir) {
  dir = _dir;
};

double Angle::getRadians() {
  return clampRadians(dir);
};
