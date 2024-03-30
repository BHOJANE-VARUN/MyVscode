#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int i,int n,int sum,vector<vector<int>>&dp)
{
    if(i>n or sum>(n*(n+1))/4.0)
    {
        if(sum==((n*(n+1))/4.0))
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int incl =  (solve(i+1,n,sum+i,dp))%MOD;
    int excl =  (solve(i+1,n,sum,dp))%MOD;
    return dp[i][sum] = (incl+excl)%MOD;
}
//subset sum of n*n+1/2 
// at any state if we used upto i elements and we have make k sum 
// so dp[i][sum] should tell us that how many ways are there to make k sum with i elements 
// if we get no. of ways to make sum-i by i-1 elements then we can find dp[i][sum];
// or we can get no. of ways to make sum by i-1 elements
// dp[i][sum] = dp[i-1][sum] + dp[i-1][sum-i]
// dp[i][0] = 1;
int solveit(int n)
{
    int sum = (n*(n+1))/4;
    //base case
    vector<vector<int>> dp(n+1,vector<int> (sum+2,0));
    for(int i =0;i<n;i++) dp[i][0] = 1;
    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<=sum;j++)
        {
            int excl = dp[i-1][j]%MOD;
            int incl =0;
            if(j-i>=0)
            {
                incl = dp[i-1][j-i]%MOD;
            }
            dp[i][j] = (excl + incl)%MOD;
        }
    }
    return dp[n-1][sum];
}

signed main()
{
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    if(sum%2)
    {
        cout<<0<<endl;
        return 0;
    }
    // vector<vector<int>> dp(n+3,vector<int> (sum+100,-1));
    // int ans = solve(1,n,0,dp);
    int ans = solveit(n);
    cout<<ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}