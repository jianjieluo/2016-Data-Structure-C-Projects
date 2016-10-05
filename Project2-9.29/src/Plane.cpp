// write by Junjun on 10.4
// modify by longj on 10.5

#include "Plane.hpp"
#include <iostream>

Plane::Plane() : m_flt_num(-1), m_clock_start(-1), m_state(null) {}

/**
 * initial a plane with its number, time and status
 */
Plane::Plane(int flt, int time, Plane_status status)
    : m_flt_num(flt), m_clock_start(time), m_state(status) {
  std::cout << "Plane number" << flt << "ready to";
  if (status == arriving)
    std::cout << "land" << std::endl;
  else if (status == departing)
    std::cout << "take off" << std::endl;
}

// processes a Plane wantting to use Runway, when Queue is full
void Plane::refuse() const {
  std::cout << "Plane number" << m_flt_num;
  if (m_state == arriving)
    std::cout << "directed to another airport" << std::endl;
  else if (m_state == departing)
    std::cout << "told to try to takeoff again later" << std::endl;
}

// processes a Plane that is landding at the specified time
void Plane::land(int time) const {
  int wait = time - m_clock_start;
  std::cout << time << ":Plane number " << m_flt_num << "landed after" << wait
            << " time unit" << ((wait == 1) ? "" : "s")
            << " in the takeoff queue." << std::endl;
}

// processes a Plane that is taking off at the specified time
void Plane::fly(int time) const {
  int wait = time - m_clock_start;
  std::cout << time << ":Plane number " << m_flt_num << " took off after"
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << "in the takeoff queue." << std::endl;
}

// return the time that the Plane entered the airport system
int Plane::started() const { return m_clock_start; }
