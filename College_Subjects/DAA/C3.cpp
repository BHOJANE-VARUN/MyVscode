// Problem Statement no. 09
// Check if it is posible to transform one string to another
// Statement: Given 2 strings s1 and s2(uppercase).
// Check if it is possible to convert s1 to s2 by performing following operations
// 1. Make some lowercase letters uppercase
// 2. Delete all the lowercase letters

// Input s1 = daBcd s2 = ABC
// Output yes

#include <bits/stdc++.h>
using namespace std;

// Function to check if s1 can be converted to s2 using rules
bool check(string s1, string s2)
{
    // calculate length
    int n = s1.length();
    int m = s2.length();

    bool dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = false;
        }
    }

    // mark 1st position as true
    dp[0][0] = true;

    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (dp[i][j])
            {
                // If uppercase in s1 are same as s2
                if (j < s2.length() && (toupper(s1[i]) == s2[j]))
                {
                    dp[i + 1][j + 1] = true;
                }

                if (!isupper(s1[i]))
                {
                    dp[i + 1][j] = true;
                }
            }
        }
    }
    return (dp[n][m]);
}

// Driver code
int main()
{
    string s1, s2;
    cout<<"Enter any two strings to find if rules apply to them"<<endl;
    cin>>s1;
    cin>>s2;
    if (check(s1, s2))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
