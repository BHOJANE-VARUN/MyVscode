#include <bits/stdc++.h>
using namespace std;
// bool valid(int x, int y, int n)
// {
//     if (0 <= x && x <= n - 1 && 0 <= y && y <= n - 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
// {
//     // Code here
//     int n = N;
//     int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
//     int x1 = KnightPos[0] - 1, y1 = KnightPos[1] - 1;

//     if (x1 == tx && y1 == ty)
//         return 0;

//     vector<vector<bool>> visited(n, vector<bool>(n, false));

//     queue<pair<int, int>> q;
//     q.push({x1, y1});
//     visited[x1][y1] = true;

//     int ans = 0;
//     while (!q.empty())
//     {

//         int size = q.size();
//         ans++;
//         while (size != 0)
//         {
//             pair<int, int> p = q.front();
//             q.pop();

//             int xx = p.first;
//             int yy = p.second;

           

//             size--;
//         }
//     }

//     return ans;
// }
bool isValid(int i, int j, int n, vector<vector<bool>> &visited)
{
    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false)
    {
        return true;
    }
    return false;
}
int solve(int ax[],int ay[],pair<int,int> &tar, int n, int x, int y, vector<vector<bool>> &visit, vector<vector<int>> &dp)
{
    if (x == tar.second - 1 && y == tar.first - 1)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    int ans = 100000;
    visit[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + ax[i];
        int ny = y + ay[i];

        if (isValid(nx, ny, n, visit))
        {
            ans = min(ans,1 + solve(ax,ay,tar,n,nx,ny,visit,dp));
        }
    }
    visit[x][y] = 0;
    dp[x][y] = ans;
    return ans;
}
int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size, vector<vector<int>> &dp)
{
    // Write your code here.
    vector<vector<bool>> visit(size + 1, vector<bool>(size + 1, false));
     int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
    int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
    return solve(ax,ay,targetPosition, size, knightPosition.second - 1, knightPosition.first - 1, visit, dp);
}
int main()
{
    // 6
    // 1 1
    // 4 5
    pair<int, int> pos = {1, 1}, tar = {4, 5};
    vector<vector<int>> dp(7, vector<int>(7, -1));

    cout << minSteps(pos, tar, 6, dp);
    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
}