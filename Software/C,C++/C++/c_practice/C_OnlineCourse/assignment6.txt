/*
Peer-graded Assignment: Write a function that prints a table of values for sine and cosine between (0, 1)
*/
#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
    double interval;
    int i;
    //loop from 0 to 10
    for(i = 0; i <=10; i++)
    {
        interval = i/10.0; //value is between 0 and 1
        printf("sin( %lf ) = %lf \t cos( %lf ) = %lf \n", interval, sin(interval),  interval, cos(interval));
    }
    return 0;
}