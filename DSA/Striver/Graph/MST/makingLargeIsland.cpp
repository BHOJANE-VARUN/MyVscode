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
class DisjointSet
{
    

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet obj(n * n + 1);
        int dir[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int ele = i * n + j;
                    for (int a = 0; a < 4; a++)
                    {
                        int row = dir[a] + i;
                        int col = dir[a + 1] + j;
                        if (row >= 0 and col >= 0 and row < n and col < n and grid[row][col] == 1)
                        {
                            int ele2 = row*n + col;
                            obj.unionBySize(ele,ele2);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int cnt =0;
                    set<int> parents;
                    for (int a = 0; a < 4; a++)
                    {
                        int row = dir[a] + i;
                        int col = dir[a + 1] + j;
                        if (row >= 0 and col >= 0 and row < n and col < n and grid[row][col] == 1)
                        {
                            int ele = row*n + col;
                            parents.insert(obj.findUPar(ele));
                        }
                    }
                    for(const auto& var:parents) cnt += obj.size[var];
                    ans = max(ans,cnt+1);
                }  
            }
        }
        return ans==INT_MIN?n*n:ans;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}