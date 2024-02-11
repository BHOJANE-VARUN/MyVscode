#include <bits/stdc++.h> 
int solve(int i,int j,vector<int> &a,vector<vector<int>> &dp)
{
    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MAX;
    for(int k = i;k<j;k++)
    {
        int temp = (a[i-1] * a[k] * a[j]) + solve(i, k, a,dp) + solve(k+1, j, a,dp);
        mini = min(mini,temp);
    }
    return dp[i][j] = mini;
}
int table(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
    
    int n = arr.size();
    for(int i=n-1;i>=1;i--)
    {
        for(int j =i+1;j<n;j++)
        {
          int mini = INT_MAX;
            for(int k = i;k<j;k++)
            {
                int temp = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(mini,temp);
            }
          dp[i][j] = mini;
        }
        
    }
    return dp[1][n-1];
}
int minMultiplicationOperations(vector<int> &arr)
{
    //    Write your code here
    // vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
    // return solve(1,arr.size()-1,arr,dp);
    return table(arr);
}