#include "position.h"

Position::Position() {
  r = 0.0;
  phi = Angle(0.0);
};
Position::Position(double _r, Angle _phi) {
  r = _r;
  phi = _phi;
};
