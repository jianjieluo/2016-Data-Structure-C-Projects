//
//  main.cpp
//  Porject2
//
//  Created by D_ on 16/10/3.
//  Copyright © 2016年 lucky star. All rights reserved.
//

#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>

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
  int fuel;
  double arrival_rate, departure_rate;
    // 检验是否出现冲突情况

  bool m_emergency = false;
  initialize(end_time, queue_limit, arrival_rate, departure_rate);
  Random variable(false);
  Runway small_airport(queue_limit);
  
  for (int current_time = 0; current_time < end_time; current_time++) {
    // loop over time intervals

    Plane moving_plane;
    // current arrival requests
    int number_arrivals = variable.poisson(arrival_rate);
    for (int i = 0; i < number_arrivals; i++) {
      // 用随机数生成燃油数
        fuel = variable.random_integer(0, 20)% 10;
      Plane current_plane(flight_number++, current_time, fuel, arriving);
      if (m_emergency == false && current_plane.get_status() == urgency) {
        m_emergency = true;
        moving_plane = current_plane;
        small_airport.before_crash(current_time);
      }
      if (small_airport.can_land(current_plane) != success)
        current_plane.refuse();
    }

    // current departure requests
    int number_departures = variable.poisson(departure_rate);
    for (int j = 0; j < number_departures; j++) {
      // 用随机数生成燃油数
        fuel = variable.random_integer(0, 20) % 10;
      Plane current_plane(flight_number++, current_time, fuel, departing);
      if (small_airport.can_depart(current_plane) != success)
        current_plane.refuse();
    }

    switch (small_airport.activity(current_time, moving_plane)) {
      // let at most one Plane onto the Runway at current_time
      case land:
        //  新增降落失败时候前查看飞机场的情况
        if (!moving_plane.land(current_time) && m_emergency == false) {
            small_airport.before_crash(current_time);
            m_emergency = false;
        }
        break;
      case takeoff:
        moving_plane.fly(current_time);
        break;
      case idle:
        run_idle(current_time);
    
    }
  }
  small_airport.shut_down(end_time);
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
