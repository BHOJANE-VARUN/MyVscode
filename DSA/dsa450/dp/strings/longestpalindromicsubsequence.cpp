#include <bits/stdc++.h>
using namespace std;
// bool checkpalin(string &str)
// {
//     int i = 0, high = str.length() - 1;
//     while (high > i)
//     {
//         if (str[i] == str[high])
//         {
//             i++, high--;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return true;
// }
// void solve(string &s, string output, int i, int &ans)
// {
//     if (i == s.length())
//     {
//         if (checkpalin(output))
//            {  int tmep = output.length();
//               ans = max(ans,tmep);
//            }
//         return;
//     }

//     output.push_back(s[i]);
//     solve(s, output, i + 1, ans);
//     output.pop_back();
//     solve(s, output, i + 1, ans);
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
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string str = s;
    reverse(s.begin(),s.end());
    return table(str,s);
}
int main()
{
    cout << longestPalindromeSubsequence("bbbab");
}