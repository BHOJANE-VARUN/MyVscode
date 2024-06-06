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
    // Function to find the number of islands.
    bool valid(int i, int j, int n, int m)
    {
        if (i >= 0 and i < n and j >= 0 and j < m)
            return true;
        else
            return false;
    }
    void visitor(vector<vector<char>> &grid, vector<vector<bool>> &visit, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        visit[i][j] = 1;
        vector<pair<int, int>> neighbors = {
            {i - 1, j},     // top
            {i - 1, j + 1}, // top-right
            {i, j + 1},     // right
            {i + 1, j + 1}, // bottom-right
            {i + 1, j},     // bottom
            {i + 1, j - 1}, // bottom-left
            {i, j - 1},     // left
            {i - 1, j - 1}  // top-left
        };

        for (auto ele : neighbors)
        {
            int a = ele.first, b = ele.second;
            if (valid(a, b, n, m) and !visit[a][b] and grid[a][b] == '1')
                visitor(grid, visit, a, b);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visit[i][j] and grid[i][j]=='1')
                {
                    cnt++;
                    visitor(grid, visit, i, j);
                }
            }
        }
        return cnt;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}