#include <bits/stdc++.h>
using namespace std;
void DFS(unordered_map<int,list<int>> &mp,vector<vector<int>> &brig,vector<bool> &visited,vector<int> &low,vector<int> &parent,int &timer,vector<int> &dis,int node)
{
    low[node] = dis[node] = timer++;
    visited[node] = true;
    for(auto i:mp[node])
    {
        if(!visited[i])
        {
            parent[i] = node;
            DFS(mp,brig,visited,low,parent,timer,dis,i);
            low[node] = min(low[node],low[i]);
            if(low[i]>dis[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(i);
                brig.push_back(temp);
            }
        }
        else{
            if(i!=parent[node])
            {
                low[node] = min(low[node],dis[i]);
            }
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> mp;
    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    vector<vector<int>> brig;
    vector<bool> visited(v);
    vector<int> low(v);
    vector<int> parent(v);
    vector<int> dicover(v);
    for(int i =0;i<v;i++)
    {
        if(!visited[i])
        {
            int timer =0;
            DFS(mp,brig,visited,low,parent,timer,dicover,i);
        }
    }
    return brig;
}
int main()
{
    return 0;
}