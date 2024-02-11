#include <bits/stdc++.h> 
using namespace std;
int solve(int i,int j,vector<int> &a,vector<vector<int>> &dp)
{
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini =INT_MIN;
    for (int k = i; k <=j; k++)
    {   int temp = a[i-1] * a[k] * a[j+1];
        int l = solve(i,k-1,a,dp); 
        int r = solve(k+1,j,a,dp);
        mini = max(mini,temp+l+r);
    }
    
    return dp[i][j] =mini;
}
int maxCoins(vector<int>& a)
{
	// Write your code here.
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>> dp(a.size()+1,vector<int> (a.size()+1,-1));
    return solve(1,n,a,dp);
}
int main()
{
    vector<int> vec = {7, 1 ,8};
    cout<<maxCoins(vec);
}