#include<stdio.h>
int binarysearch(int arr[],int n ,int t)
{
    int min =0;
    int max = n-1;
    int mid = (max + min )/2;
    while (min<=max)
    {
       if(arr[mid]==t)
       {
        return 1;
       }
       else if(arr[min]>t)
       {
        max = max -1;
       }
       else
       {
        min = min + 1;
       }
      mid = (max + min )/2; 
    }
   return -1;

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
        printf("enter the %dth element ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n enter the to be searched");
   
    scanf("%d",&d);
    int  ans = binarysearch(arr,n,d);
    printf("%d",ans);
    return 0;
}