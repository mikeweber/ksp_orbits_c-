#include "clamp_radians.h"
#include "tau.h"

double clampRadians(double radians) {
  radians = fmod(radians + TAU / 2, TAU);
  if (radians < 0)
    radians += TAU;

  return radians - TAU / 2;
};
