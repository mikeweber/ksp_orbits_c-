#include <string>
#include "position.h"

#ifndef CelestialBody_H
#define CelestialBody_H

using namespace std;

class Time {
  public:
    Time();
  operator double() const;
};

class CelestialBody {
  public:
    string name;
    double radius;
    long int mu;
    double v;
    double a;
    double arg_of_pe;
    Position pos;
    double e;
    CelestialBody* bodies_in_soi;

    CelestialBody();
    CelestialBody(string, double, long int, double, double, double, double, double);
    ~CelestialBody();
    Position* getPositionAtTime(Time);
    double getMeanAnomaly(double);

  protected:
    init(string, double, long int, double, double, double, double);
};

#endif
