#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
int solve(int a, int b, vector<vector<int>> &dp)
{
    if (a == b)
    {
        return 0;
    }
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    if (a == 1)
        return b - 1;
    if (b == 1)
        return a - 1;

    int ans = INT_MAX;
    for (int i = 1; i <= ((a + 1) / 2); i++)
    {
        int lef = solve(i, b, dp);
        int rig = solve(a - i, b, dp);
        ans = min(ans, lef + rig + 1);
    }
    for (int i = 1; i <= ((b + 1) / 2); i++)
    {
        int lef = solve(a, i, dp);
        int rig = solve(a, b - i, dp);
        ans = min(ans, lef + rig + 1);
    }
    return dp[a][b] = ans;
}
int solveit(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++)
    {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++)
    {
        dp[1][i] = i - 1;
    }
    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if(i==j)
            {
                dp[i][j] = 0;
                continue;
            }
            int ans = INT_MAX;
            for (int k = 1; k <= ((i + 1) / 2); k++)
            {
                int lef = dp[k][j];
                int rig = dp[i-k][j];
                ans = min(ans, lef + rig + 1);
            }
            for (int l = 1; l <= ((j + 1) / 2); l++)
            {
                int lef = dp[i][l];
                int rig = dp[i][j-l];
                ans = min(ans, lef + rig + 1);
            }
            dp[i][j] = ans;
        }
    }
    return dp[a][b];
}
signed main()
{
    int a, b;
    cin >> a >> b;
   // vector<vector<int>> dp(a + 2, vector<int>(b + 2, -1));
    //cout << solve(a, b, dp) << endl;
    cout<<solveit(a,b)<<endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}