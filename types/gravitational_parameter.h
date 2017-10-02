#ifndef GravitationalParameter_H
#define GravitationalParameter_H

class GravitationalParameter {
  public:
    GravitationalParameter(double);
    operator double() {
      return mu;
    };
  private:
    double mu;
};

#endif

