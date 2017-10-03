#include <string>
#include "celestial_body.h"
#include "../utils/clamp_radians.h"
#include "../utils/tau.h"

using namespace std;

CelestialBody::CelestialBody() {};

void CelestialBody::init(string body_name, double body_radius, GravitationalParameter body_mu, double semimajor_axis, Position* pos, Angle body_arg_of_pe, double eccentricity, Angle prograde) {
  name      = body_name;
  radius    = body_radius;
  mu        = body_mu;
  a         = semimajor_axis;
  arg_of_pe = body_arg_of_pe;
  e         = eccentricity;
  m         = pos->phi;
};

CelestialBody::~CelestialBody() {};

Position* CelestialBody::getPositionAtTime(Time t) {
  double ecc = getEccentricity();
  Angle M    = getMeanAnomaly(t, ecc) * -1;
  double S   = M.sin();
  double C   = M.cos();
  double esq = pow(ecc, 2);

  Angle phi = Angle(getArgumentOfPeriapsis() - atan2((1 - esq) * S, C - ecc));
  double r  = (a * (1 - esq)) / (1 + ecc * phi.cos());
  return new Position(r, phi);
};

Angle CelestialBody::getMeanAnomaly(Time t) {
  return getMeanAnomaly(t, getEccentricity());
};

Angle CelestialBody::getMeanAnomaly(Time t, double ecc) {
  Angle M;

  if (ecc > 1) {
    Angle E = getEccentricAnomaly(TAU / 4, ecc);
    M = Angle(E - ecc * E.sin());
  } else {
    double mm = getMeanMotion() * t;
    M = Angle(getInitMeanAnomaly() + getMeanMotion() * t);
  }
  return M;
};

Angle CelestialBody::getEccentricAnomaly(Angle M, double ecc) {
  return getEccentricAnomaly(M, ecc, M, 1);
};

Angle CelestialBody::getEccentricAnomaly(Angle M, double ecc, Angle E, int tries) {
  double F = E - ecc * M.sin() - M;

  if (tries > MAX_ECCENTRIC_ANOMALY_TRIES || fabs(F) < ECCENTRIC_ANOMALY_TOLERANCE) {
    return E;
  } else {
    E = Angle(E - F / (1 - ecc * E.cos()));
    return getEccentricAnomaly(M, ecc, E, tries + 1);
  }
};

Angle CelestialBody::getInitMeanAnomaly() {
  return m;
};

Angle CelestialBody::getMeanMotion() {
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

Angle CelestialBody::getArgumentOfPeriapsis() {
  return arg_of_pe;
};

