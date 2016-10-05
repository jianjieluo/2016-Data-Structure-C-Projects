#include "Plane.hpp"
#include <iostream>
using std::cout;
using std::endl;

Plane::Plane() {
  flt_num = -1;
  clock_start = -1;
  state = null;
}

Plane::Plane(int flt, int time, Plane_status status) {
  flt_num = flt;
  clock_start = time;
  state = status;
  cout << "Plane number" << flt << "ready to";
  if (status == arriving)
    cout << "land" << endl;
  else
    cout << "take off" << endl;
}

// processes a Plane wantting to use Runway, when Queue is full
void Plane::refuse() const {
  cout << "Plane number " << flt_num;
  if (state == arriving)
    cout << "directed to another airport" << endl;
  else
    cout << "told to try to takeoff again later" << endl;
}

// processes a Plane that is landding at the specified time
void Plane::land(int time) const {
  int wait = time - clock_start;
  cout << time << ":Plane number " << flt_num << "landed after" << wait
       << " time unit" << ((wait == 1) ? "" : "s") << " in the takeoff queue."
       << endl;
}

// processes a Plane that is taking off at the specified time
void Plane::fly(int time) const {
  int wait = time - clock_start;
  cout << time << ":Plane number " << flt_num << " took off after" << wait
       << " time unit" << ((wait == 1) ? "" : "s") << "in the takeoff queue."
       << endl;
}

// return the time that the Plane entered the airport system
int Plane::started() const { return clock_start; }
