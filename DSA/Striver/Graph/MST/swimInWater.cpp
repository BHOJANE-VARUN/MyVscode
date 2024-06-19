class DisjointSet
{
    vector<int> rank, parent, size;

public:
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
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet obj(n * n);
        int dir[] = {0, 1, 0, -1, 0};
        int t =0;
        for (t = 0; t < n * n; t++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] <= t)
                    {
                        for (int a = 0; a < 4; a++)
                        {
                            int row = dir[a] + i;
                            int col = dir[a + 1] + j;
                            if (row >= 0 and col >= 0 and row < n and col < n and grid[row][col]<=t)
                            {
                                obj.unionByRank(grid[row][col],grid[i][j]);
                            }
                        }
                    }
                }
            }
            if(obj.findUPar(grid[0][0])==obj.findUPar(grid[n-1][n-1]))
            {
                break;
            }
        }
        return t;
    }
};
// most optimal by using dijstra's variation
class Solution {
public:
    using grid_info = tuple<int,int,int>;

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<grid_info, vector<grid_info>, greater<>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        visit[0][0] = true;
        pq.push(grid_info(grid[0][0], 0, 0));
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int v = get<0>(t), x = get<1>(t), y = get<2>(t);
            if (x == m-1 && y == n-1) {
                return v;
            }
            for (auto &d: dir) {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >=n || visit[nx][ny]) {
                    continue;
                }
                visit[nx][ny] = true;
                pq.push(grid_info(max(v, grid[nx][ny]), nx, ny));
            }
        }

        return -1;
    }
};