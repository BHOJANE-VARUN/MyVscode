#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &prices, int index, int buy)
{
    if (index == prices.size())
        return 0;

    if (buy)
    {
        int incl = (-prices[index]) + solve(prices, index + 1, 0);
        int exl = 0 + solve(prices, index + 1, 1);
        return max(incl, exl);
    }
    else
    {
        int sell = prices[index] + solve(prices, index + 1, 1);
        int notsell = solve(prices, index + 1, 0);
        return max(sell, notsell);
    }
}
int solvemem(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[buy][index] != -1)
        return dp[buy][index];

    if (buy)
    {
        int incl = (-prices[index]) + solvemem(prices, index + 1, 0, dp);
        int exl = 0 + solvemem(prices, index + 1, 1, dp);
        return dp[buy][index] = max(incl, exl);
    }
    else
    {
        int sell = prices[index] + solvemem(prices, index + 1, 1, dp);
        int notsell = solvemem(prices, index + 1, 0, dp);
        return dp[buy][index] = max(sell, notsell);
    }
}
int table(vector<int> &pr)
{
    int n = pr.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {   int ans =0;
            if (j)
            {
                int incl = (-pr[i]) + dp[i + 1][0];
                int exl = 0 + dp[i + 1][1];
                ans = max(incl, exl);
            }
            else
            {
                int sell = pr[i] + dp[i + 1][1];
                int notsell = dp[i + 1][0];
                ans = max(sell, notsell);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][0];
}
int tableoptim(vector<int> &pr)
{
    int n = pr.size();
    vector<int> cur(2, 0),prev(2,0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {   int ans =0;
            if (j)
            {
                int incl = (-pr[i]) + prev[0];
                int exl = 0 + prev[1];
                ans = max(incl, exl);
            }
            else
            {
                int sell = pr[i] + prev[1];
                int notsell = prev[0];
                ans = max(sell, notsell);
            }
            cur[j] = ans;
        }
        prev = cur;
    }
    return cur[1];
}
int bestTimeToBuyAndSellStockII(vector<int> &prices)
{
    // Write your code here.
    // vector<vector<int>> dp(2, vector<int>(prices.size() + 1, -1));
    // return solvemem(prices, 0, 1, dp);
}
int main()
{
    vector<int> vec = {7, 1, 5, 4, 3, 6};
    // cout << bestTimeToBuyAndSellStockII(vec);
    cout << tableoptim(vec);
}
