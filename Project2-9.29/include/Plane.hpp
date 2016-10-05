//
//  Plane.hpp
//  Porject2
//
//  Created by D_ on 16/10/3.
//  Copyright © 2016年 lucky star. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
enum Plane_status {null, arriving, departing};
class Plane {
public:
    Plane();
    Plane(int flt, int time, Plane_status status);
    void refuse() const;
    void land(int time) const;
    void fly(int time) const;
    int started() const;
private:
    int flt_num;
    int clock_start;
    Plane_status state;
};
#endif /* Plane_hpp */
