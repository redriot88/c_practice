#include <stdio.h>
#include <math.h> 
//we need to call on math functions for trig

//gravity is constant and we declare as a float function
float getGravity (void){
    return 9.8; 
}
//declare flight time float function with variables declared
float getFlightTime(float distance, float velocity, float angle){
    return (distance / velocity) * cos(angle);
}
//declared height float function with variables declared
float getHeight(float distance, float velocity, float angle){
    float time = getFlightTime(distance, velocity, angle);
    //always remember to decalre variables used in functions when initialising
    float gravity = getGravity(); //constant function variable
    return ((velocity * sin(angle)) * time) - (0.5 * gravity * time * time);
}

int main (void){
    float dist;
    float vel;
    float ang;

    printf("Enter distance, intial velocity and angle of elevation: ");
    scanf("%f %f %f", &dist, &vel, &ang);

    //to call getFlightTime
    float t = getFlightTime(dist, vel, ang);

    //to call getHeight
    float h = getHeight(dist, vel, ang);

    // printf("%f %f %f", dist, vel, angle); //to test input
    printf("Duration: %f seconds, height: %f metres.\n", t, h);

    return 0;
}
