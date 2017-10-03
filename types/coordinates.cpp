#include "coordinates.h"

Coordinates::Coordinates() {
  x = 0.0;
  y = 0.0;
};

Coordinates::Coordinates(double _x, double _y) {
  x = _x;
  y = _y;
};

Coordinates Coordinates::operator+(Velocity vel) {
  return Coordinates(x + vel.getX(), y + vel.getY());
};

Coordinates Coordinates::operator+(Coordinates coords) {
  return Coordinates(x + coords.x, y + coords.y);
};

Position Coordinates::toPosition() {
  return Position(sqrt(x * x + y * y), atan2(y, x));
};

