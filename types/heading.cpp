#include "heading.h"
#include "../utils/clamp_radians.h"

Heading::Heading() {
  dir      = 0.0;
  unsetRelativeAngle();
};

Heading::Heading(double _dir) {
  dir      = _dir;
  unsetRelativeAngle();
};

Heading::Heading(double _dir, Angle* _relative) {
  dir      = _dir;
  relative = _relative;
};

double Heading::getRadians() {
  return clampRadians(dir + getRelativeAngle());
};

void Heading::setRelativeAngle(Angle* angle) {
  relative = angle;
};

void Heading::unsetRelativeAngle() {
  relative = new Angle(0.0);
};

double Heading::getRelativeAngle() {
  return relative->dir;
};

