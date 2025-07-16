#include <stdio.h> //printf, scanf
#include <math.h>  //pow, sin(), cos()

//gravity is constant and  declared as float for calcs
//another way to do this is #define G 9.8 and can also use double for more accurate calcs
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
    //can also write double dist, vel, ang //to store program inputs
    //double t, h //to store program outputs

    printf("Enter the following separated by spaces: 1. horizontal displacement (m)\n 2. magnitude of initial velocity (m/s)\n 3. angle of elevation in radians: \n");
    scanf("%f %f %f", &dist, &vel, &ang);

    //to call getFlightTime
    float t = getFlightTime(dist, vel, ang);

    //to call getHeight
    float h = getHeight(dist, vel, ang);

    // printf("%f %f %f", dist, vel, angle); //to test input
    printf("Duration: %f seconds, height: %f metres.\n", t, h);

    return 0;
}
