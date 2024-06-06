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
int solve(vector<int> &arr, int i, int j)
{
    if (i == j or abs(i - j) == 1)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int k = i + 1; k < j; k++)
    {
        cout << arr[i] << " " << arr[k] << " " << arr[j] << endl;
        int cur = arr[i] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k, j);
        ans = max(ans, cur);
    }
    return ans;
}
// 1 2 3 4

int table(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, 0));
    for (int i = 2; i < n - 1; i++)
    {
        dp[3][i] = arr[i] * arr[i - 1] * arr[i - 2];
    }
    for (int i = 4; i <= n; i++)
    {
        for (int v = i - 1; v < n; v++)
        {
            int ans = INT_MIN;
            for (int k = v-i+2; k < v; k++)
            {
               // cout << arr[i] << " " << arr[k] << " " << arr[j] << endl;
                int cur = arr[v-i+1] * arr[k] * arr[v] + solve(arr, i, k) + solve(arr, k, j);
                ans = max(ans, cur);
            }
            dp[i][v] =  ans;
        }
    }
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return solve(arr, 0, N - 1);
}
signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    matrixMultiplication(arr, n);
    // dusro ka code copy karne se ghar nahi chalta bhai
}