//
//  main.c
//  lab1
//
//  Created by Serhii Kopach on 28.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>

#include "math.h"

void testCalc (double x, double y, double z) {
    double result = calc(x, y, z);
    printf("%.12lf\n", result);
}

int main(int argc, const char * argv[]) {
    testCalc(1.5, 2.5, 0.5);
    
    return 0;
}
