#include <bits/stdc++.h>
using namespace std;
// int solve(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
// {
//     if (j == str2.length() || i == str1.length())
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (str1[i] == str2[j])
//         dp[i][j] = 1 + solve(str1, str2, i + 1, j + 1, dp);
//     else
//         dp[i][j] = max(solve(str1, str2, i + 1, j, dp), solve(str1, str2, i, j + 1, dp));
//     return dp[i][j];
// }
int table(string &st, string &str)
{
    vector<vector<int>> dp(str.length()+1, vector<int>(st.length()+1, 0));
    for (int i = str.length()-1; i>=0; i--)
    {
        for (int j = st.length()-1; j>=0; j--)
        {
            if (str[i] == st[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
int tablememoptim(string & s,string &t)
{   int m = s.length(),n = t.length();
    vector<int> prev(m+1, 0), curr(n+1, 0);

	for(int i=m; i>=0; i--){
		for(int j=n; j>=0; j--){
			if(s[i+1] == t[j+1]) curr[j] = 1 + prev[j+1];
			else curr[j] = max(prev[j], curr[j+1]);
		}
        prev = curr;
	}
    return prev[0];
}
int getLengthOfLCS(string &str1, string &str2)
{
    // Write your code here.

    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, -1));
    // return solve(str1,str2,0,0);
   // return solve(str1, str2, 0, 0, dp);
   return table(str1,str2);
}
int main()
{ // xnhqxfedlkoc tljvyzrlcynfhkmflnzkaicapgdasudlfojfnaqqa
    string str1 = "abcsfldjlfsj";
    string str2 = "aclfjsabc";
    cout << tablememoptim(str1, str2);
}