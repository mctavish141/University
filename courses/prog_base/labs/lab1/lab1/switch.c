//
//  switch.c
//  lab1
//
//  Created by Serhii Kopach on 28.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include "switch.h"

#include <stdlib.h>
#include <math.h>

int sizeOfDataType (int dataType) {
    switch (dataType) {
        case 0:
            return sizeof(char);
        case 1:
            return sizeof(signed);
        case 2:
            return sizeof(short);
        case 3:
            return sizeof(unsigned);
        case 4:
            return sizeof(long);
        case 5:
            return sizeof(unsigned long long);
        case 6:
            return sizeof(float);
        case 7:
            return sizeof(double);
        default:
            return 0;
    }
}

int exec (int op, int a, int b) {
    int n0 = 4;
    int n1 = 1;
    
    if (op < 0) {
        int c = a;
        a = b;
        b = c;
        op *= -1;
    }
    
    switch (op) {
        case 0:
            return -a;
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return (b == 0) ? 0 : a / b;
        case 5:
            return abs(a);
        case 6:
            return pow(a, b);
        case 7:
        case 13:
        case 77:
            return (b == 0) ? 0 : a % b;
        case 8:
            return (a > b) ? a : b;
        case 9:
            return (a < b) ? a : b;
        case 10:
            return abs(a) * sizeOfDataType(abs(b) % 8);
        case 11:
            return ((a - n1) == 0) ? 0 : ((n0 + 1) * cos(b * M_PI) / (a - n1));
        default:
            /*if ((op < 100) && (((a + 1) == 0) || ((b + 1) == 0))) {
                return NAN;
            }
            return (op < 100) ? (op % abs(a + 1)) + (op % abs(b + 1)) : -1;*/
            /*if (op >= 100) {
                return -1;
            }
            return (((a + 1) == 0) || ((b + 1) == 0)) ? NAN : (op % abs(a + 1)) + (op % abs(b + 1));*/
            return (op >= 100) ? -1 : (((a + 1) == 0) || ((b + 1) == 0)) ? 0 : (op % abs(a + 1)) + (op % abs(b + 1));
    }
}