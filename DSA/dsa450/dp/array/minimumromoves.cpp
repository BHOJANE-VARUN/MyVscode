#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int n,int k ,int i,int j,vector<vector<int>> &dp)
{   
    if(i==j || arr[j]-arr[i]<=k) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    return  dp[i][j] = 1 + min(solve(arr,n,k,i+1,j,dp),solve(arr,n,k,i,j-1,dp));
} 
int minimumRemovals(vector<int>& arr, int n, int k)
{
sort(arr.begin(),arr.end());
 int i =0,j=n-1;
 while(j>i)
 {
    if(arr[j]-arr[i]<=k)
    {
        break;
    }
    if(arr[j-1]-arr[i]>arr[j]-arr[i+1])
    {
        i++;
    }else{
        j--;
    }
 }
 return n-1-(j-i);
}
int main()
{//5 12
//5 5 -20 17 -12 
    vector<int> arr = {5 ,5 ,-20 ,17 ,-12};
    //-20,-12,5,5,17
 cout<<minimumRemovals(arr,5,12);
}
