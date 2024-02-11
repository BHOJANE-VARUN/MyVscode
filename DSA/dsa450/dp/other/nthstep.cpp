#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7; 
long long solve(long long n,vector<long long> &dp)
{
    if(n==1 || n==2)
    {
        return n;
    }
    if(n==0) return 1;

    if(dp[n])return dp[n]%mod;

    return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
    
}
long long tabular(int n)
{
    vector<long long> table(n+5,0);
    long long pre1=1,pre2=1;
    for(int i =2;i<n+1;i++)
    {
        long long ans = (pre1+pre2)%mod;
        pre2 = pre1;
        pre1 = ans;
    }
    return pre1;
}
int countDistinctWays(int n) {
   // vector<long long> dp(n+4,0);
    //return solve(n,dp);
   // return tabular(n);
   long long pre1=1,pre2=1;
    for(int i =2;i<n+1;i++)
    {
        long long ans = (pre1+pre2)%mod;
        pre2 = pre1;
        pre1 = ans;
    }
    return pre1;
}
/*#include <bits/stdc++.h>
long long mod = 1e9+7; 
long long solve(long long n,vector<long long> &dp)
{
    if(n==1 || n==2)
    {
        return n;
    }
    if(n==0) return 1;

    if(dp[n])return dp[n]%mod;

    return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
    
}
int countDistinctWays(int n) {
    vector<long long> dp(n+4,0);
    return solve(n,dp);
}*/
int main()
{
    cout<<countDistinctWays(10);
}