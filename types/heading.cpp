#include "heading.h"
#include "../utils/clamp_radians.h"

Heading::Heading() {
  dir      = 0.0;
  relative = 0.0;
};

Heading::Heading(double _dir) {
  dir      = _dir;
  relative = 0.0;
};

Heading::Heading(double _dir, Angle* _relative) {
  dir      = _dir;
  relative = _relative->dir;
};

double Heading::getRadians() {
  return clampRadians(dir + relative);
}
