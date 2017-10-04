#include <iostream>
#include <string>
#include "models/sun.h"
#include "models/planet.h"
#include "models/ship.h"
#include "utils/tau.h"
#include "types/angle.h"
#include "types/velocity.h"
#include "types/position.h"
#include "types/heading.h"

using namespace std;

int main()
{
  Sun kerbol(string("Kerbol"), 2.616e8, 1.1723328e18);
  Planet kerbin(&kerbol, string("Kerbin"), 6e5, 3.5316e12, 13599840256, -Angle(TAU / 2), 0.0, 0.0, 8.4159286e7);

  Time t = Time(0.0);
  cout << "The current time is " << t << endl;
  Position pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos.r << ", phi: " << pos.phi << " at time " << t << endl;

  t = Time(4601700.0);
  cout << "The current time is " << t << endl;
  pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos.r << ", phi: " << pos.phi << " at time " << t << endl;

  cout << "Creating ship" << endl;
  Ship* ship = new Ship(&kerbin, "Duna Mission", Velocity(100.0, Angle(TAU / 2)), Position(kerbin.radius + 1e5, Angle(TAU / 2)), Heading(0.0), 0.25, 5e3);
  cout << "Ship " << ship->name << " is in orbit of " << ship->getParentName() << endl;
  ship->setRelativeHeading(TAU / 36);
  cout << "Ship heading: " << ship->getHeading() << endl;
  cout << "Ship velocity: " << ship->getVelocity() << endl;
  cout << "Ship prograde: " << ship->getPrograde()->getRadians() << endl;
  cout << "Ship position: r: " << ship->pos.r << ", phi: " << ship->pos.phi << endl;
  ship->setThrottle(1.0);
  ship->step(t, 1.0);
  Coordinates coords = ship->getLocalCoordinates(t);
  cout << "Ship coordinates: (" << coords.x << ", " << coords.y << ")" << endl;
  return 0;
};
