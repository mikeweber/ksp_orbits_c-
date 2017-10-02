#ifndef Time_H
#define Time_H

class Time {
  public:
    Time(double);
    operator double() {
      return t;
    };
  private:
    double t;
};

#endif
