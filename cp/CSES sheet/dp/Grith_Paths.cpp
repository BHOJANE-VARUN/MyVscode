#include <bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
int solve(vector<vector<bool>> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int n = arr.size();
    if (i == arr.size() - 1 and j == arr.size() - 1)
    {
        return 1;
    }
    int lef = 0;
    int rig = 0;
    if (j + 1 < n and arr[i][j + 1])
    {
        lef = solve(arr, i, j + 1, dp) % MOD;
    }
    if (i + 1 < n and arr[i + 1][j])
    {
        rig = solve(arr, i + 1, j, dp) % MOD;
    }
    return dp[i][j] = ((lef + rig) % MOD);
}
int solvit(vector<vector<bool>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int lef = 0;
            int rig = 0;
            if (j - 1 >=0 and arr[i][j - 1])
            {
                lef = dp[i][j-1] % MOD;
            }
            if (i - 1 >= 0 and arr[i - 1][j])
            {
                rig = dp[i-1][j] % MOD;
            }
            dp[i][j] = (lef+rig)%MOD + dp[i][j];
        }
    }
    return dp[n-1][n-1];
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<bool>> vec(n, vector<bool>(n, true));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '*')
                vec[i][j] = false;
        }
    }
    if (vec[n - 1][n - 1] == false or vec[0][0] == false)
    {
        cout << 0 << endl;
        return 0;
    }
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // int ans = solve(vec, 0, 0, dp);
    int ans = solvit(vec);
    cout << ans << endl;
    // dusro ka code copy karne se khar nahi chalta bhai
}