#include <bits/stdc++.h>
using namespace std;
int solve(string &s, string &t, int i, int j)
{
    if (i == s.length())
        return t.length() - j;
    if (j == t.length())
        return s.length() - i;

    if (s[i] == t[j])
    {
        return solve(s, t, i + 1, j + 1);
    }
    else
    {
        int rep = 1 + solve(s, t, i + 1, j + 1);
        int delan = 1 + solve(s, t, i, j + 1);
        int insans = 1 + solve(s, t, i + 1, j);

        return min(rep, min(delan, insans));
    }
}
int solvemem(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length())
        return t.length() - j;
    if (j == t.length())
        return s.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = solvemem(s, t, i + 1, j + 1, dp);
    }
    else
    {
        int rep = 1 + solvemem(s, t, i + 1, j + 1, dp);
        int delan = 1 + solvemem(s, t, i, j + 1, dp);
        int insans = 1 + solvemem(s, t, i + 1, j, dp);

        return dp[i][j] = min(rep, min(delan, insans));
    }
}
int table(string &s, string &t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    for (int j = 0; j <= t.length(); j++)
        dp[s.length()][j] = t.length() - j;

    for (int i = 0; i <= s.length(); i++)
        dp[i][t.length()] = s.length() - i;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        for (int j = t.length() - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                 dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                int rep = 1 + dp[i + 1][j + 1];
                int delan = 1 + dp[i][j + 1];
                int insans = 1 + dp[i + 1][j];

                 dp[i][j] = min(rep, min(delan, insans));
            }
        }
    }
    return dp[0][0];
}
int tableoptim(string &s, string &t)
{
    vector<int> next(t.length() + 1, 0),cur(t.length()+1,0);
    for (int j = 0; j <= t.length(); j++)
        next[j] = t.length() - j;


    for (int i = s.length() - 1; i >= 0; i--)
    {
        for (int j = t.length() - 1; j >= 0; j--)
        {   cur[t.length()] = s.length() -i;
            int ans =0;
            if (s[i] == t[j])
            {
                ans = next[j + 1];
            }
            else
            {
                int rep = 1 + cur[j + 1];
                int delan = 1 + next[j + 1];
                int insans = 1 + next[j];

                ans = min(rep, min(delan, insans));
            }
            cur[j] = ans;
        }
        next = cur;
    }
    return next[0];
}
int editDistance(string &str1, string &str2)
{
    // write you code here
    return solve(str1, str2, 0, 0);
}
int main()
{
    string str1 = "horse", str2 = "ror";
    cout << tableoptim(str1, str2);
}