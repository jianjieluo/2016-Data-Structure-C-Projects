#ifndef Runway_hpp
#define Runway_hpp

#include <stdio.h>
#include "Extended_queue.hpp"
#include "Plane.hpp"
#include "enum.hpp"

class Runway {
 public:
  Runway(int limit);
  ~Runway() {}
  Error_code can_land(const Plane& current);
  Error_code can_depart(const Plane& current);
  Runway_activity activity(int time, Plane& moving);
  bool landingQueueEmpty() const { return landing.isEmpty();}
  bool landingQueueFull() const { return landing.isFull();}
  bool takeoffingQueueEmpty() const { return takeoffing.isEmpty();}
  void shut_down(int time) const;
 
 private:
  Extended_queue<Plane> landing;
  Extended_queue<Plane> takeoffing;
  int queue_limit;
  int num_land_requests;
  int num_takeoff_requests;
  int num_landings;
  int num_takeoffs;
  int num_land_accepted;
  int num_takeoff_accepted;
  int num_land_refused;
  int num_takeoff_refused;
  int land_wait;
  int takeoff_wait;
  int idle_time;
};
#endif /* Runway_hpp */
