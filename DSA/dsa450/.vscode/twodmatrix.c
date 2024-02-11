#include<stdio.h>
void main()
{
    int arr[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter the %dth row and %d colum",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }

        
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d  ",arr[i][j]);
        }

        printf("\n");
    }
    
}