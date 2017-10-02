#include "ship.h"

Ship::Ship() {
};

Ship::Ship(CelestialBody* _parent, string _name, Velocity _vel, Position _pos, Prograde _pro, Heading _heading) {
  parent  = _parent;
  name    = _name;
  vel     = _vel;
  pos     = _pos;
  pro     = _pro;
  heading = _heading;
};

GravitationalParameter Ship::getParentMu() {
  return parent->mu;
};

string Ship::getParentName() {
  return parent->name;
};
