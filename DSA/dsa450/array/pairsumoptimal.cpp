#include<iostream>
using namespace std;
int pairSum(int arr[], int n, int target){
    int count = 0;
    if (target > arr[n - 1])
    {
       int s=n-1,i=0;
       while (s!=i)
       {
        if (arr[s]+arr[i]==target)
        {
            count++;
            s--;
            i=0;
        }
        else if(arr[s]+arr[i]>target)
        {
            s--;
            i=0;
        }
        else
        {
            i++;
        }
        
        
        
       }
        
    }
    else
    {
        int s=0,i=n-1;
       while (s!=i)
       {
        if (arr[s]+arr[i]==target)
        {
            count++;
            s++;
            i=n-1;
        }
        else if(arr[s]+arr[i]>target)
        {
            s++;
            i=n-1;
        }
        else
        {
            i--;
        }
        
        
        
       }
        
    }
    
    return count;
}
int main()
{
    int t = 6;
    int n =5;
    int arr[10]={1,2,3,4,5};
    int a = pairSum(arr,n,t);
    cout<<a;
}
