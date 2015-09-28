//
//  condition.c
//  lab1
//
//  Created by Serhii Kopach on 28.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include "condition.h"

#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int isPowerOfTwo (int number) {
    double power = log2(number);
    if (floor(power) == power) {
        return 1;
    } else {
        return 0;
    }
}

int satisfies (int a, int b, int c) {
    int n0 = 4;
    int n1 = 1;
    
    if ((a < 0) && (b < 0) && (c < 0)) {
        int modmin, sum2;
        if ((a < b) && (a < c)) {
            modmin = abs(a);
            sum2 = b + c;
        } else {
            if ((b < a) && (b < c)) {
                modmin = abs(b);
                sum2 = a + c;
            } else {
                modmin = abs(c);
                sum2 = a + b;
            }
        }
        
        if ((sum2 < -256) && (isPowerOfTwo(modmin) == 1) && (modmin < 256)) {
            return 1;
        } else {
            if (((abs(sum2) - modmin) < 16) || (sum2 < 16)) {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        if ((a < 0) || (b < 0) || (c < 0)) {
            if (((a < 0) && (b >= 0) && (c >= 0)) || ((a >= 0) && (b < 0) && (c >= 0)) || ((a >= 0) && (b >= 0) && (c < 0))) {
                if (a < 0) {
                    return (a > -256);
                }
                if (b < 0) {
                    return (b > -256);
                }
                return (c > -256);
            } else {
                if (a < 0) {
                    return (((b + c) * (n0 + n1)) > -256);
                }
                if (b < 0) {
                    return (((a + c) * (n0 + n1)) > -256);
                }
                return (((a + b) * (n0 + n1)) > -256);
            }
        } else {
            int max;
            max = (a > b) ? a : b;
            max = (max > c) ? max : c;
            int min;
            min = (a < b) ? a : b;
            min = (max < c) ? max : c;
            
            double maxShortInt = pow(2, sizeof(short) * 8) / 2 - 1;
            return (pow(max, min) <= maxShortInt);
        }
    }
    
    return 0;
}