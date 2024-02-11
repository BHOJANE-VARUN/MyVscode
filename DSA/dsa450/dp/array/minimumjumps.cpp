#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n, int index, vector<int> &dp)
{
    if (index >= arr.size() - 1)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int flag = INT_MAX;
    for (int i = index; i < index + arr[index]; i++)
    {
        int temp = solve(arr, n, i + 1, dp);
        if (temp != INT_MAX)
            flag = min(flag, 1 + temp);
    }
    return dp[index] = flag;
}
int table(vector<int> &arr, int n)
{
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {   int l;
        for (int j = 1; j <=arr[i]; j++)
        {
            
            if (i+j<n && dp[i+j]!= INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i+j]);
        }
        
    }
    return dp[0];
}
int minimumJumps(vector<int> &arr, int n)
{
    // write your code here
    vector<int> dp(n + 1, -1);
    return solve(arr, n, 0, dp);
}
int main()
{
    vector<int> vec = {1, 1, 1, 1};
    cout << table(vec, vec.size());
}