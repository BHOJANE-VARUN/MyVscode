#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> mp;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }

    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);
    key[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u, mini = INT_MAX;
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false and mini > key[v])
            {
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true;
        for (auto ele : mp[u])
        {
            int v = ele.first;
            int w = ele.second;
            if (mst[v] == false and key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i =2;i<=n;i++)
    {
        int v = i;
        int u = parent[v];
        int w = key[i];
        ans.push_back({{u,v},w});
    }
    return ans;
}
int main()
{
    return 0;
}
