#include <bits/stdc++.h> 
using namespace std;
int solve(int arr[],int n,int k,int i,int count)
{   if(i+k-1>=n) return 0; 
    
    int sum =0;
    for(int j =i;j<i+k;j++)
    sum += arr[j];
    if(count) sum += solve(arr,n,k,i+k,0);
    int exl = solve(arr,n,k,i+1,count);
    return max(sum,exl);
}
int maxSumTwoSubarray(int arr[], int N, int K)
{
	// Write your code here.
    int i =0;
    int d = solve(arr,N,K,i,1);
    return d;
    
}
int main()
{//9 2

    int arr[] = {4, 8 ,-1 ,-23, 8 ,7 ,-6, 5 ,0};
    int n =9,k=2;
    cout<<maxSumTwoSubarray(arr,n,k);
}
