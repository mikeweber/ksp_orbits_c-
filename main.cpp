#include <iostream>
#include <string>
#include "model/planet.h"
#include "tau.h"

using namespace std;

int main()
{
  Planet kerbin(string("Kerbin"), 6e5, 13599840256, -TAU / 2, 0.0, 0.0, 8.4159286e7);
  cout << "Created planet named " << kerbin.name << " with a surface radius of " << kerbin.radius << endl;
  return 0;
};
