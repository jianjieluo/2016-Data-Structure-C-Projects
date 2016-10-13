#include "Runway.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

// initialize the runway
Runway::Runway(int limit) {
  queue_limit = limit;
  num_land_requests = num_takeoff_requests = 0;
  num_land_accepted = num_takeoff_accepted = 0;
  num_landings = num_takeoffs = 0;
  num_land_refused = num_takeoff_refused = 0;
  land_wait = takeoff_wait = idle_time = 0;
}

/* if possible, the Plane current is added to the landding Queue; otherwise, an
 * Error_code of overflow is returned. The Runway statistics are updated*/
// Uses:class Extended_queue
Error_code Runway::can_land(const Plane& current) {
  Error_code result;
  if (landing.size() < queue_limit) {
    result = landing.push(current);
  } else {
    result = fail;
  }
  num_land_requests++;
  if (result != success)
    num_land_refused++;
  else
    num_land_accepted++;
  return result;
}

// Post: If possible, the Plane current is added to the takeoff Queue; otherwise, an
// Error_code of overflow is returned. The Runway statistics are update.
// Uses: class Extended_queue.
Error_code Runway::can_depart(const Plane &current) {
  Error_code result;
  if (takeoffing.size() < queue_limit)
    result = takeoffing.push(current);
  else
    result = fail;
  num_takeoff_requests++;
  if (result!=success)
    num_takeoff_refused++;
  else
    num_takeoff_accepted++;
  return result;
}

/* if the landing Queue has entries, its front Plane is copied to the parameter
 * moving and a result land is returned. Otherwise, if the takeoff Queue has
 * entries, its front Plane is copied to the parameter moving and a result
 * takeoff is returned. Otherwise, idle is returned,. Runway statistics are
 * updated*/
Runway_activity Runway::activity(int time, Plane& moving) {
  Runway_activity in_progersss;
  if (!landing.isEmpty()) {
    landing.retrieve(moving);
    land_wait += time - moving.started();
    num_landings++;
    in_progersss = land;
    landing.pop();
  } else if (!takeoffing.isEmpty()) {
    takeoffing.retrieve(moving);
    takeoff_wait += time - moving.started();
    num_takeoffs++;
    in_progersss = takeoff;
    takeoffing.pop();
  } else {
    idle_time++;
    in_progersss = idle;
  }
  return in_progersss;
}

// Runwfstream.h: No such file or directory

void Runway::before_crash(int time) const {
    std::ofstream s("../data/summary_p5.txt", std::ios_base::app);
    if (!s)  { cout << "open the file failed !!!" << endl;
        exit(0);
    }
    s << endl << "This is the situation before the plane crash" << endl
      << "Total number of planes processed \t\t\t"
      << (num_land_requests + num_takeoff_requests) << endl
      << "Percentage of time runway idle \t\t\t"
      << 100.0 * (((float)idle_time) / ((float)time)) << "% " << endl
      << ((float)num_takeoff_requests) / ((float)time) << " per time unit "
      << endl;
    s.close();
}

void Runway::shut_down(double rate, int queue_limit, int time) const {
    std::ofstream s("../data/summary_p5.txt", std::ios_base::app);
  if (!s) cout << 1233333;
  s    << endl
       << "This is the total situation : " << endl
       << "Sumualation has conluded after " << time << " time units." << endl
       << "Queue limit : \t\t\t" << queue_limit << endl
       << "Arrival rate & departure rate : \t\t\t" << rate << endl
       << "Total number of planes processed \t\t\t"
       << (num_land_requests + num_takeoff_requests) << endl
       << "Total number of planes asking to land \t\t" << (num_land_requests)
       << endl
       << "Total number of planes asking to take off \t\t" << (num_takeoff_requests)
       << endl
       << "Total number of planes accepted for landing \t\t" << (num_land_accepted)
       << endl
       << "Total number of planes accepted for takeoff \t\t"
       << (num_takeoff_accepted) << endl
       << "Total number of planes refused for landing \t\t" << (num_land_refused)
       << endl
       << "Total number of planes refused for takeoff\t\t" << (num_takeoff_refused)
       << endl
       << "Total number of planes that landed\t\t\t" << (num_landings) << endl
       << "Total number of planes that took off\t\t\t" << (num_takeoffs) << endl
       << "Total number of planes that left in landing queue\t" << landing.size()
       << endl
       << "Total number of planes that left in takeoff queue \t"
       << takeoffing.size() << endl;
  s    << "Percentage of time runway idle \t\t\t"
       << 100.0 * (((float)idle_time) / ((float)time)) << "% " << endl;
  s    << "Average wait in landing queue \t\t\t\t"
       << ((float)land_wait) / ((float)num_landings) << " time units" << endl;
  s    << "Average wait in takeoff queue \t\t\t\t"
       << ((float)takeoff_wait) / ((float)num_takeoffs) << " time units" << endl;
  s    << "Average obserbed rate of planes wanting to land \t"
       << ((float)num_land_requests) / ((float)time) << " per time unit" << endl;
  s    << "Average obserbed rate of planes wanting to take off \t"
       << ((float)num_takeoff_requests) / ((float)time) << " per time unit" << endl
       << "The plane that crashed : " << Plane::crash << endl
    << endl;
  s.close();
}
