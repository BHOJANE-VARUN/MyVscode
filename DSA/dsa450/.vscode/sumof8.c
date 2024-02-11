#include<stdio.h>
void main()
{   int n,sum=0;
    printf("enter the number upto n ");
    scanf("%d",&n);
    for (int i = 0; i < n+1; i++)
    {
       sum += i;
    }
    printf("sum of number is %d",sum);
    
}