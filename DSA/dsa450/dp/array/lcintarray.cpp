#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int> &arr,int i,int prev,vector<vector<int>> &dp)
{
	if(i==arr.size())
	{
		return 0;
	}

	if(dp[i][prev]!=-1) return dp[i][prev];

	int excl = solve(arr, i+1, prev,dp);
	int incl =0;
	if(arr[i]>arr[prev])
	{
		incl = 1 + solve(arr, i+1,i,dp);
	}
	return dp[i][prev] = max(excl,incl);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{	rack.insert(rack.begin(),0);
	vector<vector<int>> dp(n+2,vector<int> (n+3,-1));
	return solve(rack,1,0,dp);
}
int main()
{
    vector<int> ved = {9 ,1 ,2 ,8};
    cout<<maxIncreasingDumbbellsSum(ved,ved.size());
}