#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
printf("enter the size of array");
scanf("%d",&n);
int arr[n];
for (int i = 0 ;i <n; i++)
{
    printf("enter the %dth element:",i+1);
    scanf("%d",&arr[i]);
}
int low = 0;
int high = n;
int mid = (high+low)/2;
int key,flag=0;
printf("enter the key to be searched");
scanf("%d",&key);
while (low<=high)
{
    if (key==arr[mid])
    {
       printf("key is present");
       flag = 1;
       break;
    }
    else if (key<arr[mid])
    {
        high = mid-1;
    }
    else
    {
        low = mid +1;
    }
    mid = (high+low)/2; 
}
if (flag==0)
{
    printf("key is not present");
}



}