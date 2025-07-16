/**
Author: redriot88
Date: 16/07/2025
Purpose: This program calculates duration and the height of an object that follows projectile motion.
**/
/**
Including necessary directives and macros i.e. Gravity
**/
#include <stdio.h> //for printf, scanf
#include <math.h>  //for pow, sin(), cos()

#define GRAVITY 9.8
double getGravity(void){
  return GRAVITY;
}

//declare functions of flight time as double function with variables defined
/**
getFlightTime calculate flight duration.
inputs: 
-distance = horizontal displacement of projectile (m)
-velocity = intial velocity of projectile (m/s)
-angle = intial angle in radians
-flight duration (s) returned as double
**/
double getFlightTime(double distance, double velocity, double angle){
    return (distance / velocity) * cos(angle);
}

//declared height float function with variables declared
/**
getHeight calculate and return flight height in reference to intial point of motion
inputs:
-velocity = intial velocity of projectile (m/s)
-angle = intial angle in radians
-time is calculated via flight duration (s) before calling this function
-flight hright (m) returned as double
**/
double getHeight(double distance, double velocity, double angle){
    double time = getFlightTime(distance, velocity, angle);
    //always remember to decalre variables used in functions when initialising
    return ((velocity * sin(angle)) * time) - (0.5 * GRAVITY * pow(time,2.0));
}

/**
main
**/
int main (void){
    double dist, vel, ang; //to store program inputs
    double t, h //to store program outputs

  /**
  Requests user to input parameters clearly
  **/
    printf("Enter (separated by spaces):\n"
"1. Distance (m)\n"
"2. Initial velocity (m/s)\n"
"3. Angle (radians)\n"
"> ");
    scanf("%lf %lf %lf", &dist, &vel, &ang);

    //to call getFlightTime
    double t = getFlightTime(dist, vel, ang);

    //to call getHeight
    double h = getHeight(dist, vel, ang);

    printf("Duration: %.2f seconds, height: %.2f metres.\n", t, h);
  
    return 0;
}
