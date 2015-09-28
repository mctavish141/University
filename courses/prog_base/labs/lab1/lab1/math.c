//
//  math.c
//  lab1
//
//  Created by Serhii Kopach on 28.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include "math.h"

#include <math.h>

int validate (double x, double y, double z, int n0, int n1) {
    // Validating a0:
    
    if ((x - y) == 0) {
        return 0;
    }
    if (z == 0) {
        return 0;
    }
    double poweredNumber = pow(x - y, 1 / z);
    if ((poweredNumber == 0) || (poweredNumber == NAN)) {
        return 0;
    }
    
    // Validating a1:
    
    if (x == 0) {
        return 0;
    }
    /*if (((n0 + 1) * fabs (x + y)) == 0) {
        return 0;
    }*/
    
    // Validating a2:
    
    if (sin(x) == 0) {
        return 0;
    }
    
    return 1;
}

double calc (double x, double y, double z) {
    double a0, a1, a2;
    
    int n0 = 4;
    int n1 = 1;
    
    if (validate(x, y, z, n0, n1) == 0) {
        return NAN;
    }
    
    a0 = pow(x, y + 1) / pow(x - y, 1 / z);
    
    a1 = (n0 * y) + (z / x);
    //a1 = y / ((n0 + 1) * fabs (x + y));
    
    a2 = sqrt(fabs((cos(y) / sin(x)) + n1));
    
    double a = a0 + a1 + a2;
    
    return a;
}