#include <bits/stdc++.h> 
using namespace std;
int *getProductArrayExceptSelf(int *arr, int n)
{
    long long mod = 1e9+7;
    long long  totalmul = 1;
    for(int i =0;i<n;i++)
    {
        totalmul =(totalmul%mod * arr[i]%mod)%mod;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        arr[i]= totalmul/temp;
    }
    return arr;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int  n = 5;
    int ne[5]=getProductArrayExceptSelf(*arr,n);
    for(int i = 0;i<n;i++)cout<<ne[i];
}