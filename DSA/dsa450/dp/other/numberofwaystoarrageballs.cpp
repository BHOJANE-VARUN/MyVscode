#include <bits/stdc++.h> 
using namespace std;
long long mod = 1e9+7;
long long solve(int a,int b,int c,int prev,vector<vector<vector<vector<long long>>>> &dp)
{
	if(a==0 && b==0 && c==0)
	return 1;
	if(a<0 || b<0 || c<0) return 0;

    if(dp[a][b][c][prev]!=-1) return dp[a][b][c][prev];
	int ans =0;
	if(prev!=1) ans += solve(a-1,b,c,1,dp)%mod;
	if(prev!=2) ans += solve(a,b-1,c,2,dp)%mod;
	if(prev!=3) ans += solve(a,b,c-1,3,dp)%mod;
	return dp[a][b][c][prev] = ans;
}
long long int totalWays(int a, int b, int c)
{
	// Write your code here.
	vector<vector<vector<vector<long long>>>> dp(a+1,vector<vector<vector<long long>>> (b+1,vector<vector<long long>> (c+1,vector<long long> (4,-1))));
	return solve(a,b,c,0,dp);
}
int main()
{
    cout<<totalWays(2,1,1);
}