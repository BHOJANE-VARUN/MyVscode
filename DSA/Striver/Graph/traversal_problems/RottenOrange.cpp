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
    void visitor(vector<vector<int>> &grid, vector<vector<bool>> &visit, int i, int j,vector<vector<int>> &arr,int cur)
    {
        int n = grid.size(), m = grid[0].size();
        visit[i][j] = 1;
        vector<pair<int, int>> neighbors = {
            {i - 1, j},     // top
            {i, j + 1},     // right
            {i + 1, j},     // bottom   
            {i, j - 1},     // left
        };
        arr[i][j] = min(cur,arr[i][j]);
        for (auto ele : neighbors)
        {
            int a = ele.first, b = ele.second;
            if (valid(a, b, n, m) and !visit[a][b] and grid[a][b] == '1')
                visitor(grid, visit, a, b,arr,cur+1);
        }
        visit[i][j] = 0;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<int>> arr(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        vector<vector<bool>> visit(grid.size(),vector<bool> (grid[0].size(),0));
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    visitor(grid,visit,i,j,arr,0);
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    if(arr[i][j]==0)
                        return -1;
                    ans = max(ans,arr[i][j]);
                }
            }
        }
        return ans;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}