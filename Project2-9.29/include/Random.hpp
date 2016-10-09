#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <cmath>

class Random {
public:
  Random() {}
  Random(bool pseudo = true);
  double random_real();
  int poisson(double mean);

  ~Random() {}
private:
  int reseed();
  int seed, multiplier, add_on;
};
#endif
