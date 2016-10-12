
#include "Random.hpp"
#include <time.h>
#include <climits>

Random::Random(bool pseudo) {
  if (pseudo) seed = 1;
  else seed = time(NULL) % INT_MAX;
  multiplier = 2743;
  add_on = 5923;
}

double Random::random_real() {
  double max = INT_MAX + 1.0;
  double temp = reseed();
  if (temp < 0) temp = temp + max;
  return temp / max;
}

int Random::random_integer(int low, int high) {
    if (low > high) return random_integer(high, low);
    else return ((int)((high - low + 1) * random_real())) + low;
}
int Random::poisson(double mean) {
  double limit = exp(-mean);
  double product = random_real();
  int count = 0;
  while (product > limit) {
    count++;
    product *= random_real();
  }
  return count;
}

int Random::reseed() {
  seed = seed * multiplier + add_on;
  return seed;
}
