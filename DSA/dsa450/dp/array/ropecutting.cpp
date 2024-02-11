#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i + 1 == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 10000;
    for (int k = 0; k < cuts.size(); k++)
    {
        if (cuts[k] != -1 && i <= cuts[k] && cuts[k] <= j)
        {
            int num = cuts[k];
            cuts[k] = -1;
            int temp = (j - i);
            int l = solve(i, num, cuts, dp);
            int r = solve(num, j, cuts, dp);
            cuts[k] = num;
            mini = min(mini, temp + l + r);
        }
    }
    return dp[i][j] = (mini == 10000 ? 0 : mini);
}
// new approch for sorted array
int solvesort(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;

    int mini = 10000;
    for (int k = i; k <= j; k++)
    {
        int temp = (cuts[j + 1] - cuts[i - 1]) + solvesort(i, k - 1, cuts) + solvesort(k + 1, j, cuts);
        mini = min(mini, temp);
    }
    return mini;
}
// i 1->c ,j c->1
// i c-> 1 ,j i+1-> c
int table(vector<int> &a, int c, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = 10000;
            for (int k = i; k <= j; k++)
            {
                int temp = (a[j + 1] - a[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, temp);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    // return solve(0,n,cuts,dp);
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    //sort(cuts.begin(), cuts.end());
    return table(cuts,c,n);
}
int main()
{
    vector<int> vec = {1, 3, 4};
    cout << cost(5, vec.size(), vec);
}