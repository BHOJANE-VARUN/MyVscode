#include<stdio.h>
void main()
{
    int arr[5][5] = {{1,2,3,4,5},{1,25,3}};
    for (int i = 0; i<5; i++)
    {
        for(int j =0; j<5 && arr[i][j]!=0;j++)
        {
            printf("%d   ",arr[i][j]);
        }
    }
    
}