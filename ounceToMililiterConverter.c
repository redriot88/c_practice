#include <stdio.h>

int main (void){
    float volume; //initialise float for ounces
    printf("This is an oz to mL convertor\n");

    printf("Enter the fluid ounces: ");
    scanf("%f", &volume); //float deals with decimals

    float amount = volume * 29.5735; //for conversion

    printf("The amount you entered was %f oz\n", volume);
    printf("The mL volume is: %f mL", amount);
    return 0;


}
