#include <iostream>
#include <string>
#include "model/sun.h"
#include "model/planet.h"
#include "tau.h"

using namespace std;

int main()
{
  Sun kerbol(string("Kerbol"), 2.616e8, 1.1723328e18);
  Planet kerbin(&kerbol, string("Kerbin"), 6e5, 3.5316e12, 13599840256, -TAU / 2, 0.0, 0.0, 8.4159286e7);
  Time t = Time(0.0);
  cout << "The current time is " << t << endl;
  Position * pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos->r << ", phi: " << pos->phi << " at time " << t << endl;

  t = Time(4601700.0);
  cout << "The current time is " << t << endl;
  pos = kerbin.getPositionAtTime(t);
  cout << "Planet " << kerbin.name << " is at position r: " << pos->r << ", phi: " << pos->phi << " at time " << t << endl;

  return 0;
};
