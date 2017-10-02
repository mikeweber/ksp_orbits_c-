#include <string>
#include <math.h>
#include "celestial_body.h"
#include "../utils/clamp_radians.h"
#include "../utils/tau.h"

using namespace std;

CelestialBody::CelestialBody() {};

void CelestialBody::init(string body_name, double body_radius, GravitationalParameter body_mu, double semimajor_axis, Position* pos, double body_arg_of_pe, double eccentricity, double prograde) {
  name      = body_name;
  radius    = body_radius;
  mu        = body_mu;
  a         = semimajor_axis;
  arg_of_pe = body_arg_of_pe;
  e         = eccentricity;
  m         = pos->phi;
};

CelestialBody::~CelestialBody() {};

Position * CelestialBody::getPositionAtTime(Time t) {
  double ecc = getEccentricity();
  double M   = getMeanAnomaly(t, ecc);
  double S   = sin(-M);
  double C   = cos(-M);
  double esq = pow(ecc, 2);

  Angle phi = Angle(getArgumentOfPeriapsis() - atan2((1 - esq) * S, C - ecc));
  double r      = (a * (1 - esq)) / (1 + ecc * cos(phi));
  return new Position(r, phi);
};

double CelestialBody::getMeanAnomaly(Time t) {
  return getMeanAnomaly(t, getEccentricity());
};

double CelestialBody::getMeanAnomaly(Time t, double ecc) {
  double M;

  if (ecc > 1) {
    double E = getEccentricAnomaly(TAU / 4, ecc);
    M = E - ecc * sin(E);
  } else {
    double mm = getMeanMotion() * t;
    M = getInitMeanAnomaly() + getMeanMotion() * t;
  }
  return clampRadians(M);
};

double CelestialBody::getEccentricAnomaly(double M, double ecc) {
  return getEccentricAnomaly(M, ecc, M, 1);
};

double CelestialBody::getEccentricAnomaly(double M, double ecc, double E, int tries) {
  double F = E - ecc * sin(M) - M;

  if (tries > MAX_ECCENTRIC_ANOMALY_TRIES || fabs(F) < ECCENTRIC_ANOMALY_TOLERANCE) {
    return E;
  } else {
    E -= F / (1 - ecc * cos(E));
    return getEccentricAnomaly(M, ecc, E, tries + 1);
  }
};

double CelestialBody::getInitMeanAnomaly() {
  return m;
};

double CelestialBody::getMeanMotion() {
  return sqrt(getParentMu() / pow(a, 3));
};

GravitationalParameter CelestialBody::getParentMu() {
  return mu;
};

string CelestialBody::getParentName() {
  return name;
};

double CelestialBody::getEccentricity() {
  return e;
};

double CelestialBody::getArgumentOfPeriapsis() {
  return arg_of_pe;
};

