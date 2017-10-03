#include <string>
#include "../types/position.h"
#include "../types/time.h"
#include "../types/gravitational_parameter.h"

#ifndef CelestialBody_H
#define CelestialBody_H

using namespace std;

const int MAX_ECCENTRIC_ANOMALY_TRIES = 30;
const double ECCENTRIC_ANOMALY_TOLERANCE = 1e-10;
class CelestialBody {
  public:
    string name;
    double radius;
    long int mu;
    double v;
    double a;
    Angle arg_of_pe;
    Position pos;
    double e;
    Angle m;

    CelestialBody();
    ~CelestialBody();
    Position * getPositionAtTime(Time);
    Angle getMeanAnomaly(Time);
    Angle getMeanAnomaly(Time, double);
    Angle getEccentricAnomaly(Angle, double);
    Angle getEccentricAnomaly(Angle, double, Angle, int);
    Angle getInitMeanAnomaly();
    Angle getMeanMotion();
    virtual GravitationalParameter getParentMu();
    virtual string getParentName();
    double getEccentricity();
    Angle getArgumentOfPeriapsis();

  protected:
    void init(string, double, GravitationalParameter, double, Position*, Angle, double, Angle);
};

#endif
