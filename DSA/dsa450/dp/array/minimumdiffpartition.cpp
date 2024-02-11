#include <bits/stdc++.h>
using namespace std; 
// int solve(int l,int r,vector<int> &arr,int n)
// {   
//     if(n==-1) return abs(l-r);

//    int la = solve(l+arr[n],r,arr,n-1);
//    int ra = solve(l,r+arr[n],arr,n-1);
//    return min(la,ra);
// }
// int solvemem(int l,int r,vector<int> &arr,int n,int ln,int rn,vector<vector<int>> &dp)
// {   
//     if(n==-1) return abs(l-r);

//     if(dp[ln][rn]!=-1)return dp[ln][rn];

//    int la = solvemem(l+arr[n],r,arr,n-1,ln+1,rn,dp);
//    int ra = solvemem(l,r+arr[n],arr,n-1,ln,rn+1,dp);
//    dp[ln][rn]= min(la,ra);
//    return dp[ln][rn];
// }


int solve(int l, int r, vector<int> &arr, int n)
{
    if (n == -1)
        return abs(l - r);

    // Check if the value is already computed and stored in the memo table
    if (memo[n][l] != -1)
        return memo[n][l];

    int la = solve(l + arr[n], r, arr, n - 1);
    int ra = solve(l, r + arr[n], arr, n - 1);

    // Store the computed value in the memo table
    return memo[n][l] = min(la, ra);
}
int table(vector<int> &arr,int n)
{
    vector<vector<int>> dp(n, vector<int>(accumulate(arr.begin(), arr.end(), 0) + 1, 0));
    for(int i =0;i<n;i++)
    {
        int la = dp[l+arr[i]][r];
        int ra = dp[l][r+arr[i]];

    // Store the computed value in the memo table
        dp[] = min(la, ra);
    }
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Initialize the memo table with -1
   vector<vector<int>> memo(n, vector<int>(accumulate(arr.begin(), arr.end(), 0) + 1, -1));
    
    return solve(0, 0, arr, n - 1);
}
int main()
{
    vector<int> vec = {4 ,7 ,14, 5 };
   cout<< minSubsetSumDifference(vec,4);
}
