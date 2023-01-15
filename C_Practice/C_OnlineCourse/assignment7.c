/*
Peer-graded Assignment: Compute the average weight for a population of elephant seals read into an array
*/
#include <stdio.h>
#include<stdlib.h>

double calcAverage(int[], int);
int numOfData(char *);



int main()
{
    /* Read data from text file */

    //open file in reading mode
    FILE *ptr = fopen("data.txt", "r");

    //check if file exists
    if(ptr == NULL)
    {
        printf("File cannot be opened \n");
        return 0;
    }
    //initialize variables
    int dataArray[10000]; //array for data, random large number for size
    int i=0; //num of data points
    //store data into dataArray
    while(fscanf(ptr, "%d\t", &dataArray[i])!=EOF)
    {
        i++;
    }
    //close file
    fclose(ptr);
    
    //calculate average from dataArray
    double average = calcAverage(dataArray, i);
    printf("\nThe average weight for this population of elephant seals is: %.3f \n", average);
    return 0;
}

//returns calculated average of array 
double calcAverage(int data[], int dataSize)
{
    int i;
    double average, total;
    for (i=0; i<dataSize; i++)
    {
        total += data[i];
    }
    average = total / dataSize;
    return average;
}