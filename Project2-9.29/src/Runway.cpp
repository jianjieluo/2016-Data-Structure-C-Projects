//
//  Runway.cpp
//  Porject2
//
//  Created by D_ on 16/10/3.
//  Copyright © 2016年 lucky star. All rights reserved.
//

#include "Runway.hpp"
#include <iostream>
using std::cout;
using std::endl;

//initialize the runway
Runway::Runway(int limit) {
    queue_limit = limit;
    num_land_requests = num_takeoff_requests = 0;
    num_land_accepted = num_takeoff_accepted = 0;
    num_landings = num_takeoffs = 0;
    num_land_refused = num_takeoff_refused = 0;
    land_wait = takeoff_wait = idle_time = 0;
}

/* if possible, the Plane current is added to the landding Queue; otherwise, an Error_code of overflow is returned. The Runway statistics are updated*/
// Uses:class Extended_queue
Error_code Runway::can_land(const Plane &current) {
    Error_code result;
    if (landing.size() < queue_limit) {
        result = landing.append(current);
    } else {
        result = fail;
    }
    num_takeoff_requests++;
    if (result != success)
        num_land_refused++;
    else
        num_land_requests++;
}

/* if the landing Queue has entries, its front Plane is copied to the parameter moving and a result land is returned. Otherwise, if the takeoff Queue has entries, its front Plane is copied to the parameter moving and a result takeoff is returned. Otherwise, idle is returned,. Runway statistics are updated*/
Runway_activity Runway::activity(int time, Plane& moving) {
    Runway_activity in_progersss;
    if (!landing.empty()) {
        landing.retrieve(moving);
        land_wait += time - moving.started();
        num_landings++;
        in_progersss = land;
        landing.serve();
    } else if (!takeoff.empty()) {
        takeoff.retrieve(moving);
        takeoff_wait += time - moving.started();
        num_takeoffs++;
        in_progersss = takeoff;
        takeoff.serve();
    } else {
        idle_time++;
        in_progersss = idle;
    }
    return in_progersss;
}

// Runway usage statistics are summarized and printed
void Runway::shut_down(int time) const {
    cout << "Sumualation has conluded after " << time << " time units." << endl
         << "Total number of planes processed "
         << (num_land_requests + num_takeoff_requests) << endl
         << "Total number of planes asking to land "
         << (num_land_requests) << endl
         << "Total number of planes asking to take off "
         << (num_takeoff_requests) << endl
         << "Total number of planes accepted for landing "
         << (num_land_accepted) << endl
         << "Total number of planes accepted for takeoff "
         << (num_takeoff_accepted) << endl
         << "Total number of planes refused for landing "
         << (num_land_refused) << endl
         << "Total number of planes refused for takeoff"
         << (num_takeoff_refused) << endl
         << "Total number of planes that landed"
         << (num_landings) << endl
         << "Total number of planes that took off"
         << (num_takeoffs) << endl
         << "Total number of planes that left in landing queue "
         << landing.size() << endl
         << "Total number of planes that left in takeoff queue "
         << takeoff.size() << endl;
    cout << "Percentage of time runway idle " << 100.0*(((float)idle_time) / ((float)time)) << "% " << endl;
    cout << "Average wait in landing queue " << ((float)land_wait) / ((float)num_landings) << "time units" << endl;
    cout << "Average wait in takeoff  queue " << ((float)takeoff_wait) / ((float)num_takeoffs) << "time units" << endl;
    cout << "Average obserbed rate of planes wanting to land" << ((float)num_land_requests) / ((float)time) << "per time unit" << endl;
    cout << "Average obserbed rate of planes wanting to take off" << ((float)num_takeoff_requests) / ((float)time) << "per time unit" << endl;
}
