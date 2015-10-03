//
//  main.c
//  Switch2
//
//  Created by Serhii Kopach on 03.10.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

// case 1...5

#include <stdio.h>

enum weekDay {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main () {
    int startDay = WEDNESDAY;
    
    printf("Enter month day: ");
    int monthDay;
    scanf("%d", &monthDay);
    
    int weekNumber = (monthDay + startDay - 1) % 7;
    
    switch (weekNumber) {
        case MONDAY:
            printf("Monday\n");
            break;
        case TUESDAY:
            printf("Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Wednesday\n");
            break;
        case THURSDAY:
            printf("Thursday\n");
            break;
        case FRIDAY:
            printf("Friday\n");
            break;
        case SATURDAY:
            printf("Saturday\n");
            break;
        case SUNDAY:
            printf("Sunday\n");
            break;
        default:
            break;
    }
    
    return 0;
}
