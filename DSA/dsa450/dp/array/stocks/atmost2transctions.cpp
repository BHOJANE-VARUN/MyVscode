#include <bits/stdc++.h>
using namespace std;
int solvemem(vector<int> &prices, int index, int buy,int tran, vector<vector<vector<int>>> &dp)
{
    if (index == prices.size() || tran==2)
        return 0;

    if (dp[index][buy][tran] != -1)
        return dp[index][buy][tran];

    if (buy)
    {
        int incl = (-prices[index]) + solvemem(prices, index + 1, 0,tran, dp);
        int exl = 0 + solvemem(prices, index + 1, 1,tran, dp);
        return dp[index][buy][tran] = max(incl, exl);
    }
    else
    {
        int sell = prices[index] + solvemem(prices, index + 1, 1,tran+1, dp);
        int notsell = solvemem(prices, index + 1, 0,tran, dp);
        return dp[index][buy][tran] = max(sell, notsell);
    }
} 
int maxProfit(vector<int> &prices, int n) {
    // Write your code here
   vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2,vector<int>(3, -1)));
    return solvemem(prices,0,1,0,dp);
}
int main()
{
    vector<int> vec = {7 ,3 ,4 ,8, 8, 4, 7, 0 };
    // cout << bestTimeToBuyAndSellStockII(vec);
    cout << maxProfit(vec,vec.size());
}