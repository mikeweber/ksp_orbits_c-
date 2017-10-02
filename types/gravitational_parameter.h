#ifndef GravitationalParameter_H
#define GravitationalParameter_H

class GravitationalParameter {
  public:
    GravitationalParameter(long int);
    operator long int() {
      return mu;
    };
  private:
    long int mu;
};

#endif

