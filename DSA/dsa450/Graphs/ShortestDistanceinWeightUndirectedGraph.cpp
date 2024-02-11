#include <bits/stdc++.h>
using namespace std;
void DFS(unordered_map<int, list<pair<int, int>>> &mp, vector<bool> &visited, vector<int> &ans, int node)
{
    visited[node] = 1;
    for (auto i : mp[node])
    {
        if (!visited[i.first])
        {
            DFS(mp, visited, ans, i.first);
        }
    }
    ans.push_back(node);
}
vector<int> topologicalsort(unordered_map<int, list<pair<int, int>>> &mp, int n)
{
    vector<bool> visited(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
        DFS(mp, visited, ans, i);
    // reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> mp;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int c = edges[i][2];
        mp[u].push_back({v, c});
    }

    vector<int> toposort = topologicalsort(mp, n);
    vector<int> distance(mp.size(), INT_MAX);
    distance[0] = 0;
    for (int i = 0; i < toposort.size(); i++)
    {
        if (distance[toposort[i]] == INT_MAX)
        {
            continue;
        }
        else
        {
            int node = toposort[i];
            for (auto u : mp[node])
            {
                int nex = u.first;
                int wei = u.second;

                distance[nex] = min(distance[nex], distance[node] + wei);
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == INT_MAX)
            distance[i] = -1;
    }
    return distance;
}
int main() { return 0; }