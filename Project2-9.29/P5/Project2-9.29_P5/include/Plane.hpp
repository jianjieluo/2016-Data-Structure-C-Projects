// write by Junjun on 10.4
// modify by longj on 10.5

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "enum.hpp"
class Plane {
 public:
  Plane();
  /**
   * initial a plane with its number, time and status
   */
  Plane(int flt, int time, int fuel, Plane_status status);
  ~Plane() {}
  void refuse() const;
  bool land(int time) ;
  void fly(int time) const;
  int started() const;
  Plane_status get_status() const;
  static int crash;
 private:
  int m_flt_num;
  int m_clock_start;
  int m_fuel;
  Plane_status m_stage;
};
#endif
