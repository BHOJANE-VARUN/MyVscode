#include <bits/stdc++.h>
using namespace std;
// bool valid(int arr[],int index,int prev)
// {
//     if(prev==-1) return 1;
//     if(arr[index]>arr[prev]) return 1;
//     else return 0;
// }
// int solvemem(int arr[], int n,int prev, int index,vector<int>& dp)
// {
//     if (index == n)
//         return 0;

//     if(dp[index]!=-1)return dp[index];

   
//     // include
//     int in=INT_MIN;
//     if (valid(arr, index,prev))
//     {   
//         in = 1 + solvemem(arr, n,index, index + 1,dp);
//     }
//      // exclude
//     int ex = solvemem(arr, n,prev, index + 1,dp);
//     dp[index] =  max(ex,in);
//     return dp[index];
// }

// int longestIncreasingSubsequence(int arr[], int n){

//   vector<int> dp;

//   dp.push_back(arr[0] );

//   for( int i = 1 ; i<n ;i++ ) {

//       int it = lower_bound( dp.begin() , dp.end() , arr[i] ) - dp.begin();

//       if( it == dp.size() ){

//         dp.push_back( arr[i] );

//       }

//       else{

//         dp[it] = arr[i];

//       }

//   }

//   return dp.size();

// }
int solvemem(int arr[],int n,int prev,int index,vector<vector<int>> &dp)
{
    if(index==n) return 0;

    if(dp[index][prev+1]!=-1)return dp[index][prev];
    int take =0;
    if(prev==-1 || arr[prev]<arr[index])
    {
        take = 1+ solvemem(arr,n,prev,index,dp);
    }
    int notg = solvemem(arr,n,prev,index+1,dp);
    return dp[index][prev+1] = max(take,notg);
}
int longestIncreasingSubsequence(int arr[], int n)
{  vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
   return solvemem(arr,n,-1,0,dp);
}
int main()
{
    int arr[] = {5,4,11,1,16,8};
    cout<<longestIncreasingSubsequence(arr,6);
}
