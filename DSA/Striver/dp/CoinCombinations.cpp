#include "vector"
long long int solve(long long int i,int *arr,long long int n,long long int sum,vector<vector<long long int>> &dp)
{
    if(sum==0)
        return 1;
     
    if(i==n)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    long long int cur =0;
    for(long long int k = i;k<n;k++)
    {
        if(sum>=arr[k])
             cur += solve(k, arr, n, sum-arr[k],dp);
    }
    return dp[i][sum] =  cur;
}
long long  table(int *arr,int n,int val)
{
    vector<vector<long long>> dp(n+1,vector<long long> (val+1,0));
    for(int i =0;i<=n;i++)
        dp[i][0] = 1;
    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=val;j++)
        {
            if(j-arr[i-1]>=0)
            {
                dp[i][j] +=  dp[i][j-arr[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n][val];
}
long countWaysToMakeChange( int *denominations,  int n,  int value)
{
    // vector<vector<long long int>> dp(n+1,vector<long long int> (value+1,-1));
    // return solve(0, denominations, n, value,dp);
    return table(denominations, n, value);
}