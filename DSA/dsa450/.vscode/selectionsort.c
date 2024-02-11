#include<stdio.h>
void selectionsort(int *arr,int n)
{
    for (int i = 0; i < n-1; i++)
    {   int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
            {
                min =j; 
            }
            
        }
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]= temp;
    }
    
}
void main()
{
    int arr[50];
    int n;
    int d;
    printf("enter the size of array");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter the %dth element ",i);
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    for (int  i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    
}