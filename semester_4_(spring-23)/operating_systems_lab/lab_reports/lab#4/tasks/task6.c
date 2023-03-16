/*
Task 6: Write a C code to declare “Time” structure that contains hour, minute and seconds as its data members. Write a function that adds
two time instances and return the resultant time to the main function.
*/

#include <stdio.h>

struct Time {
    int hour;
    int minute;
    int sec;
};

struct Time addTime (struct Time t1, struct Time t2){
    struct Time t3;
    t3.hour = t1.hour + t2.hour;
    t3.minute = t1.minute + t2.minute;
    if (t3.minute >= 60){
        t3.hour++;
        t3.minute -= 60;
    }
    t3.sec = t1.sec + t2.sec;
    if (t3.sec >= 60){
        t3.minute++;
        t3.sec-=60;
    }
    return t3;
}

void displayTime(struct Time t){
    printf("%d : %d : %d\n", t.hour, t.minute, t.sec);
}

int main(void){
    struct Time t1, t2, t3;

    t1.hour = 10;
    t1.minute = 53;
    t1.sec = 34;
    displayTime(t1);

    t2.hour = 6;
    t2.minute = 17;
    t2.sec = 43;
    displayTime(t2);

    t3 = addTime(t1, t2);
    displayTime(t3);
    return 0;
}
