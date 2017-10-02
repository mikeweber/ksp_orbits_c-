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
    double arg_of_pe;
    Position pos;
    double e;
    double m;

    CelestialBody();
    ~CelestialBody();
    Position * getPositionAtTime(Time);
    double getMeanAnomaly(Time);
    double getMeanAnomaly(Time, double);
    double getEccentricAnomaly(double, double);
    double getEccentricAnomaly(double, double, double, int);
    double getInitMeanAnomaly();
    double getMeanMotion();
    virtual GravitationalParameter getParentMu();
    virtual string getParentName();
    double getEccentricity();
    double getArgumentOfPeriapsis();

  protected:
    void init(string, double, GravitationalParameter, double, Position*, double, double, double);
};

#endif
