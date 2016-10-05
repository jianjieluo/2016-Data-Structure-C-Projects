#ifndef Plane_hpp
#define Plane_hpp

#include <cstdio>
#include "enum.hpp"
class Plane {
 public:
  Plane();
  Plane(int flt, int time, Plane_status status);
  void refuse() const;
  void land(int time) const;
  void fly(int time) const;
  int started() const;

 private:
  int flt_num;
  int clock_start;
  Plane_status state;
};
#endif /* Plane_hpp */
