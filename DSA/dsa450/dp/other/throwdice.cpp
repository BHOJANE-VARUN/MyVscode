#include <bits/stdc++.h>
using namespace std;
// void solve(int d, int f, int s, int index, int &ans, int cur)
// {if (cur == s && index==d)
//     {
//         ans++;
//         return;
//     }
//     if (index >= d)
//         return;

//     for (int i = 1; i <= f; i++)
//     {
//         solve(d, f, s, index + 1, ans, cur + i);
//     }
// }
// int solve(int d, int f, int s, int index, int cur,vector<vector<int>>& dp)
// {if (cur == s && index==d)
//     {

//         return 1;
//     }
//     if (index >= d)
//         return 0;
//     if(cur>s)return 0;

//     if(dp[index][cur]!=-1)return dp[index][cur];

//     int ans =0;
//     for (int i = 1; i <= f; i++)
//     {
//       ans += solve(d, f, s, index + 1, cur + i,dp);
//     }
//     dp[index][cur] = ans;
//     return dp[index][cur];
// }
// #include "vector"
// long long mod = 1e9 + 7;
// long long solve(int d, int f, int s, int index, int cur, vector<vector<long long>> &dp)
// {
//     if (cur == s && index == d)
//     {

//         return 1;
//     }
//     if (index >= d)
//         return 0;
//     if (cur > s)
//         return 0;

//     if (dp[index][cur] != -1)
//         return dp[index][cur];

//     long long ans = 0;
//     for (int i = 1; i <= f; i++)
//     {
//         ans = (ans + solve(d, f, s, index + 1, cur + i, dp)) % mod;
//     }
//     dp[index][cur] = ans;
//     return dp[index][cur];
// }
int table(int d, int f, int s)
{
    vector<vector<int>> dp(d + 1, vector<int>(s + 1, 0));
    long long mod = 1e9+7;
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            long long ans = 0;
            for (int k = 1; k <= f; k++)
            {   if(j-k>=0)
                ans = ans + dp[i-1][j-k] % mod;
            }
            dp[i][j] = ans;
            
        }
    }
    return dp[d][s];
}
int tableoptim(int d, int f, int s)
{
    vector<int> prev(s+1,0);
    vector<int> cur(s+1,0);
    prev[0] =1;
    long long mod = 1e9+7;
    for(int z =1;z<=d;z++)
        {for (int j = 1; j <= s; j++)
        {
            long long ans = 0;
            for (int k = 1; k <= f; k++)
            {   if(j-k>=0)
                ans = ans + prev[j-k] % mod;
            }
            cur[j] = ans;
            
        }
        prev = cur;}
    return prev[s];
}
// int diceThrows(int d, int f, int s)
// {
//     // Write your Code here.
//     //     3
//     // 2 5 10
//     // 1 6 9
//     // 2 6 8
//     vector<vector<int>> dp(d + 1, vector<int>(s + 1, -1));
//     return solve(d, f, s, 0, 0, dp);
// }
int main()
{
   // cout << diceThrows(2, 5, 10);
   cout<<tableoptim(2,5,10);
}