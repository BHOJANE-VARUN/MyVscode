#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &days, vector<int> &cost, int travel, int index)
{
    if (travel >= days[index])
        return solve(n, days, cost, travel, index + 1);
    if (travel >= days[n - 1])
        return 0;

    int one = cost[0] + solve(n, days, cost, days[index], index + 1);
    int week = cost[1] + solve(n, days, cost, days[index] + 6, index + 1);
    int mouth = cost[2] + solve(n, days, cost, days[index] + 29, index + 1);

    return min(one, min(week, mouth));
}
int solvemem(int n, vector<int> &days, vector<int> &cost, int travel, int index, vector<int> &dp)
{
    if (travel >= days[index])
        return solve(n, days, cost, travel, index + 1);
    if (travel >= days[n - 1])
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int one = cost[0] + solvemem(n, days, cost, days[index], index + 1, dp);
    int week = cost[1] + solvemem(n, days, cost, days[index] + 6, index + 1, dp);
    int mouth = cost[2] + solvemem(n, days, cost, days[index] + 29, index + 1, dp);

    dp[index] = min(one, min(week, mouth));
    return dp[index];
}
// int solvetable(int n,vector<int> days,vector<int> cost)
// {
//     vector<int> dp(n+1,-1);
//     dp[n] = 0;
//     for(int i = n-1;i>=0;i--)
//     {
//         int one = cost[0] + dp(n,days,cost,days[index],index+1,dp);
//         int week = cost[1] + solvemem(n,days,cost,days[index]+6,index+1,dp);
//         int mouth = cost[2] + solvemem(n,days,cost,days[index]+29,index+1,dp);
//     }
// }
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.

    // return solve(n,days,cost,0,0);
    vector<int> dp(n + 1, -1);
    return solvemem(n, days, cost, 0, 0, dp);
}
// second solution
int solve2(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    int one = cost[0] + solve2(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int week = cost[1] + solve2(n, days, cost, i);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int mouth = cost[2] + solve2(n, days, cost, i);

    return min(one, min(week, mouth));
}
int table(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int one = cost[0] + dp[k+1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++);

        int week = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++);
        int mouth = cost[2] + dp[i];

        dp[k] =  min(one, min(week, mouth));
    }
    return dp[0];
}
int main()
{
    vector<int> days = {2, 5};
    vector<int> cost = {1, 4, 25};
    cout << table(2, days, cost);
    // cout<<minimumCoins(2,days,cost);
}