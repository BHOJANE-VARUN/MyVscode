#include <bits/stdc++.h>
using namespace std;
int solve(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
{
    if (j == str2.length() || i == str1.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j] && i!=j)
        dp[i][j] = 1 + solve(str1, str2, i + 1, j + 1, dp);
    else
        dp[i][j] = max(solve(str1, str2, i + 1, j, dp), solve(str1, str2, i, j + 1, dp));
    return dp[i][j];
}
int LRS(string &str)
{
    vector<vector<int>> dp(str.length()+1, vector<int>(str.length()+1, -1));
   return solve(str, str, 0, 0, dp);
}
int main()
{
    string str = "abacb";
    cout << LRS(str);
}