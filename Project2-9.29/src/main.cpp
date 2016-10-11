//
//  main.cpp
//  Porject2
//
//  Created by D_ on 16/10/3.
//  Copyright © 2016年 lucky star. All rights reserved.
//

#include <iostream>
#include <random>
// #include "Plane.hpp"
#include <fstream>
#include "Extended_queue.hpp"
#include "Runway.hpp"
#include "Random.hpp"
using namespace std;

void initialize(int &end_time, int &queue_limit, double &arrival_rate,
                double &departure_rate);
void run_idle(int time);

int main(int argc, const char *argv[]) {
  int end_time;
  int queue_limit;
  int flight_number = 0;
  double arrival_rate, departure_rate;
  initialize(end_time, queue_limit, arrival_rate, departure_rate);
  Random variable(false);
  Runway Landing_runway(queue_limit); 
  Runway Takingoff_runway(queue_limit);
  for (int current_time = 0; current_time < end_time; current_time++) {
    // loop over time intervals

    // current arrival requests
    int number_arrivals = variable.poisson(arrival_rate);
    for (int i = 0; i < number_arrivals; i++) {
      Plane current_plane(flight_number++, current_time, arriving);
      bool flag = true;
      if (Landing_runway.can_land(current_plane) != success){
        current_plane.refuse();
        flag = false;
      }
      if(flag) {
        if (Takingoff_runway.takeoffingQueueEmpty()) {
          Plane current_plane_1(flight_number++, current_time, arriving);
          ++i;
          if (Takingoff_runway.can_land(current_plane_1) != success) {
            current_plane_1.refuse();
            --i;
            --flight_number;
          }
        }
      } else {
        if (Takingoff_runway.can_land(current_plane) != success) 
          current_plane.refuse();
      }
      
    }

    // current departure requests
    int number_departures = variable.poisson(departure_rate);
    for (int j = 0; j < number_departures; j++) {
      Plane current_plane(flight_number++, current_time, departing);
      bool flag = true;
      if (Takingoff_runway.can_depart(current_plane) != success){ 
        current_plane.refuse();
        flag = false;
      }
      if (flag) {
        if (Landing_runway.landingQueueEmpty()) {
          ++j;
          Plane current_plane_1(flight_number++, current_time, departing);
          if (Landing_runway.can_depart(current_plane) != success) {
            current_plane_1.refuse();
            --j;
            --flight_number;
          }
        }
      } else {
        if (Landing_runway.landingQueueEmpty()) {
          if (Landing_runway.can_depart(current_plane) != success) {
            current_plane.refuse();
          }
        }
      }
    }
    Plane moving_plane_1;
    cout << "In landing runway : " << endl;
    switch (Landing_runway.activity(current_time, moving_plane_1)) {
      // let at most one Plane onto the Runway at current_time
      case land:
        moving_plane_1.land(current_time);
        break;
      case takeoff:
        if (Landing_runway.landingQueueEmpty())
          moving_plane_1.fly(current_time);
        break;
      case idle:
        run_idle(current_time);
        break;
      default : 
        cout << "nothing happened.";
        break;
    }
    Plane moving_plane_2;
    cout << "In takingoff runway : " << endl;
    switch (Takingoff_runway.activity(current_time, moving_plane_2)) {
      // let at most one Plane onto the Runway at current_time
      case land:
        if (Takingoff_runway.takeoffingQueueEmpty())
          moving_plane_1.land(current_time);
        break;
      case takeoff:
        moving_plane_2.fly(current_time);
        break;
      case idle:
        run_idle(current_time);
        break;
      default : break;
    }
  }
  ofstream fl("./data/summary.txt", std::ios_base::app);
  fl << endl << "The Landing Runway : ";
  fl.close();
  Landing_runway.shut_down(end_time);
  fl.open("./data/summary.txt", std::ios_base::app);
  fl << "The Takingoff Runway : ";
  fl.close();
  Takingoff_runway.shut_down(end_time);
  return 0;
}

void initialize(int &end_time, int &queue_limit, double &arrival_rate,
                double &departure_rate) {
  cout << "This program simulates an airport with only one runway." << endl
       << "One plane can land or depart in each unit of time." << endl;
  cout << "Up to what number of planes can be waiting to land "
       << "or take off at any time " << endl << "Limit number:\t";
  cin >> queue_limit;
  cout << "How many units of time will the simulation run?" << endl << "End time: \t";
  cin >> end_time;
  bool acceptable = false;
  do {
    cout << "Expected number of arrivals per unit time?" << endl << "Arrival rate:\t";
    cin >> arrival_rate;
    cout << "Expected number of departures per unit time?" << endl << "Departure rate:\t";
    cin >> departure_rate;
    if (arrival_rate < 0.0 || departure_rate < 0.0)
      cerr << "These rates must be nonnegative." << endl;
    else
      acceptable = true;
    if (acceptable && arrival_rate + departure_rate > 1.0)
      cerr << "Satety Warning: This airport will become saturated. " << endl;
    cout << "------------------------------------------------------------------" << endl;
  } while (!acceptable);
}

void run_idle(int time) { cout << time << ":\tRunway is idle." << endl; }
