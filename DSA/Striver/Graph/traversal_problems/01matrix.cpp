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
class Solution
{
public:
    bool valid(int i, int j, int n, int m)
    {
        if (i >= 0 and i < n and j >= 0 and j < m)
            return true;
        else
            return false;
    }
    void bfs(vector<vector<int>> &ans, int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {i, j}});
        visit[i][j] = 1;
        while (!q.empty())
        {
            int cnt = q.front().first, row = q.front().second.first, col = q.front().second.second;
            q.pop();
            vector<pair<int, int>> neighbors = {
                {row - 1, col}, // top
                {row, col + 1}, // right
                {row + 1, col}, // bottom
                {row, col - 1}, // left
            };
            for (auto ele : neighbors)
            {
                int a = ele.first, b = ele.second;
                if (valid(a, b, n, m) and !visit[a][b])
                {
                    if(mat[a][b]==0)
                    {
                        ans[i][j] = cnt;
                        return;
                    }
                    else{
                        visit[row][col] = 1;
                        q.push({cnt+1, {a, b}});
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bfs(ans, i, j, mat);
            }
        }
        return ;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}
