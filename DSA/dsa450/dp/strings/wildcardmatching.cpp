#include <bits/stdc++.h>
using namespace std;
bool solve(string &a, string &b, int i, int j)
{
    if (i == a.length() && j == b.length())
        return true;
    if (i < a.length() && j == b.length())
        return false;
    if (i == a.length() && j < b.length())
    {
        for (int i = j; i < b.length(); i++)
        {
            if (b[i] != '*')
                return false;
        }
        return true;
    }
    if (a[i] == b[j] || b[j] == '?')
        return solve(a, b, i + 1, j + 1);
    else if (b[j] == '*')
    {
        return solve(a, b, i + 1, j) || solve(a, b, i, j + 1);
    }
    else
    {
        return false;
    }
}
bool solvemem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length() && j == b.length())
        return true;
    if (i < a.length() && j == b.length())
        return false;
    if (i == a.length() && j < b.length())
    {
        for (int i = j; i < b.length(); i++)
        {
            if (b[i] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j] || b[j] == '?')
        return dp[i][j] = solvemem(a, b, i + 1, j + 1, dp);
    else if (b[j] == '*')
    {
        return dp[i][j] = solvemem(a, b, i + 1, j, dp) || solvemem(a, b, i, j + 1, dp);
    }
    else
    {
        return dp[i][j] = false;
    }
}
bool table(string p, string t)
{
    vector<vector<int>> dp(t.length() + 1, vector<int>(p.length() + 1, 0));
    dp[0][0] = true;
    for (int i = 1; i <= p.length(); i++)
    {
        bool f = true;
        for (int k = 1; k <= i; k++)
        {
            if (p[k - 1] != '*')
                {f = false; break;}
        }
        dp[0][i] = f;
    }

    for (int i = 1; i <= t.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (t[i-1] == p[j-1] || p[j-1] == '?')
                 dp[i][j] = dp[i - 1][j - 1];
            else if (p[j-1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j-1];
            }
            else
            {
             dp[i][j] = false;
            }
        }
    }
    return dp[t.length()][p.length()];
}
bool tableoptim(string p, string t)
{
   int n = p.size();
   int m = t.size();
   vector<int>prev(m+1,0),cur(m+1,0);
   prev[0]=1;
   cur[0]=1;
   for(int i=1;i<=n;i++)
   {
      int flag = true;
      for(int k=1;k<=i;k++)
      if(p[k-1]!='*')
      {
         flag = false;
         break;
      }
      cur[0]=flag;
      for(int j=1;j<=m;j++)
      {
         int take=0,nottake=0;
         if(p[i-1]=='?' || p[i-1]==t[j-1])
         {
            take = prev[j-1];
         }
         if(p[i-1]=='*')
         {
            nottake= cur[j-1] | prev[j];
         }
         cur[j] = take | nottake;
      }
      prev = cur;
   }
   return cur[m];
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    vector<vector<int>> dp(text.length() + 1, vector<int>(pattern.length() + 1, -1));
    // return solve(text,pattern,0,0);
    return solvemem(text, pattern, 0, 0, dp);
}
int main()
{
    string p = "ab*";
    string t = "ab";
    cout << table(p, t);
}
