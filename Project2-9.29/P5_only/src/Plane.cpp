// write by Junjun on 10.4
// modify by longj on 10.5

// P6修改在构造函数 refuse(), land(), get_status()
// land()
#include "Plane.hpp"
#include <iostream>
int Plane::crash = 0;
Plane::Plane() : m_flt_num(-1), m_clock_start(-1), m_fuel(-1), m_stage(null) {}

/**
 * initial a plane with its number, time and status
 */
Plane::Plane(int flt, int time, int fuel, Plane_status status)
: m_flt_num(flt), m_clock_start(time), m_fuel(fuel), m_stage(status) {
    std::cout << "\tPlane No." << flt << " ready to ";
    // if a plane want to land, check its fuel storage
    if (status == arriving || m_fuel <= 1) {
        status = urgency;
    }
    if (status == arriving)
        std::cout << "land" << std::endl;
    else if (status == departing)
        std::cout << "take off" << std::endl;
    else if (status == urgency)
        std::cout << "land in emergency" << std::endl;
}

// processes a Plane wantting to use Runway, when Queue is full
void Plane::refuse() const {
    std::cout << "\tPlane No." << m_flt_num;
    if (m_stage == arriving || m_stage == urgency) {
        if (m_fuel <= 3) {
            std::cout << "didn't have enough fuel, so it would crash" << std::endl;
            crash++;
            return;
        }
        std::cout << " directed to another airport" << std::endl;
    }
    else if (m_stage == departing)
        std::cout << " told to try to takeoff again later" << std::endl;
}

// processes a Plane that is landding at the specified time
bool Plane::land(int time) {
    int wait = time - m_clock_start;
    if (wait > m_fuel) {
        std::cout << ":\tPlane No." << m_flt_num << " didn't take enough fuel, it would crash"
        << " in " << wait << ((wait == 1)? "":"s") << " in the landing queue" << std::endl;
        crash++;
        m_stage = urgency;
        return false;
    }
    std::cout << time << ":\tPlane No." << m_flt_num << " landed after " << wait
    << " time unit" << ((wait <= 1) ? "" : "s")
    << " in the takeoff queue." << std::endl;
    return true;
    // std::cout << "------------------------------------------------------------------" << std::endl;
}

// processes a Plane that is taking off at the specified time
void Plane::fly(int time) const {
    int wait = time - m_clock_start;
    std::cout << time << ":\tPlane No." << m_flt_num << " took off after "
    << wait << " time unit" << ((wait == 1) ? "" : "s")
    << " in the takeoff queue." << std::endl;
    // std::cout << "------------------------------------------------------------------" << std::endl;
}

// get the stage of the plane
Plane_status Plane::get_status () const {
    return m_stage;
}
// return the time that the Plane entered the airport system
int Plane::started() const { return m_clock_start; }
