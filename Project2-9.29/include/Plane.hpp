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
  Plane(int flt, int time, Plane_status status);
  void refuse() const;
  void land(int time) const;
  void fly(int time) const;
  int started() const;

 private:
  int m_flt_num;
  int m_clock_start;
  Plane_status m_state;
};
#endif
