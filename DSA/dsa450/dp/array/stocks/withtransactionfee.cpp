#include <bits/stdc++.h>
using namespace std;
int solvemem(vector<int>&prices,int index,int buy,vector<vector<int>> &dp,int &fee)
{
    if(index==prices.size()) return 0;

    if(dp[buy][index]!=-1) return dp[buy][index];

    if(buy)
    {
        int incl = (-prices[index]) + solvemem(prices,index+1,0,dp,fee);
        int exl = 0 + solvemem(prices,index+1,1,dp,fee);
        return dp[buy][index] =  max(incl,exl);
    }
    else{
        int sell = prices[index]- fee + solvemem(prices,index+1,1,dp,fee);
        int notsell = solvemem(prices,index+1,0,dp,fee);
        return dp[buy][index] = max(sell,notsell);
    }
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
     vector<vector<int>> dp(2,vector<int> (prices.size()+1,-1));
    return solvemem(prices,0,1,dp,fee);
}