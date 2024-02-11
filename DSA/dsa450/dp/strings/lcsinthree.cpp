#include <bits/stdc++.h>
using namespace std;
int solve(string &str1, string &str2,string &str3, int i, int j,int k, vector<vector<vector<int>>> &dp)
{
    if (j == str2.length() || i == str1.length() || k == str3.length())
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (str1[i] == str2[j] && str2[j]==str3[k])
        dp[i][j][k] = 1 + solve(str1, str2,str3, i + 1, j + 1,k+1, dp);
    else
        dp[i][j][k] = max(solve(str1, str2,str3, i + 1, j,k, dp),max(solve(str1,str2,str3,i,j,k+1,dp), solve(str1, str2,str3, i, j + 1,k, dp)));
    return dp[i][j][k];
}
int LCS(string A, string B, string C, int n, int m, int k)
{
	// Write your code here.
    vector<vector<vector<int>>> dp(A.length(),vector<vector<int>> (B.length(),vector<int> (C.length(),-1)));
    return solve(A,B,C,0,0,0,dp);
}
int main()
{
    string a = "code";
    string b = "coding";
    string c = "codingninjas";
    cout<<LCS(a,b,c,a.length(),b.length(),c.length());
}