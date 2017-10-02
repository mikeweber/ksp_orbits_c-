#include <iostream>
#include <string>
#include "models/sun.h"
#include "models/planet.h"
#include "models/ship.h"
#include "utils/tau.h"
#include "types/angle.h"
#include "types/velocity.h"
#include "types/position.h"
#include "types/prograde.h"
#include "types/heading.h"

using namespace std;

int main()
{
  Sun kerbol(string("Kerbol"), 2.616e8, 1.1723328e18);
  Planet kerbin(&kerbol, string("Kerbin"), 6e5, 3.5316e12, 13599840256, -Angle(TAU / 2), 0.0, 0.0, 8.4159286e7);
  Ship* ship = new Ship(&kerbin, "Duna Mission", Velocity(100.0), Position(kerbin.radius + 1e5, Angle(TAU / 2)), Prograde(TAU / 2), Heading(0.0));

  Time t = Time(0.0);
  cout << "The current time is " << t << endl;
  Position * pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos->r << ", phi: " << pos->phi << " at time " << t << endl;

  t = Time(4601700.0);
  cout << "The current time is " << t << endl;
  pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos->r << ", phi: " << pos->phi << " at time " << t << endl;

  cout << "Ship " << ship->name << " is in orbit of " << ship->getParentName() << endl;
  return 0;
};
