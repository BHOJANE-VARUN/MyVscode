#include<stdio.h>
// time complexity is big o of n square
void bubblesort(int *arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            
        }
        
    }
    
}
int main()
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
    bubblesort(arr,n);
    for (int  i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    
}