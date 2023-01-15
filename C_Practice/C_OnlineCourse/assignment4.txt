/*
 Write a program that prints the sine function for an input x between (0, 1)
*/

#include <stdio.h>
#include <math.h> //include math library for sine function 

int main()
{
    double num, sinValue;
    printf("Enter a number \n");
    scanf("%lf", &num);
    sinValue = sin(num);
    printf("Sine value is: %lf \n", sinValue);
    return 0;
}