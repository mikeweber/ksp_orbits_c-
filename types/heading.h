#include "angle.h"

#ifndef Heading_H
#define Heading_H

class Heading:public Angle {
  public:
    Heading();
    Heading(double);
    Heading(double, Angle*);
    double getRadians();

  private:
    Angle relative;
};

#endif

