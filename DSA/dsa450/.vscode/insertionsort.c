#include<stdio.h>
// time complexity is big o of n square
void insertionsort(int *arr,int n)
{
    for (int i = 1; i < n; i++)
    {   int j=i;
        while (j!=0 && arr[j-1]>arr[j] )
        {
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
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
    insertionsort(arr,n);
    for (int  i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    
}