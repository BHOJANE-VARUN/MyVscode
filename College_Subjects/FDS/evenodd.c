#include<stdio.h> 

void main()
{
    int num; // initilizing the variable
    printf("Enter the number to be checked");
    scanf("%d",&num); // taking input 
    if (num%2==0)
    {
        printf("number is even"); // even case
    }
    else{
        printf("number is odd"); // odd case
    }
    
}