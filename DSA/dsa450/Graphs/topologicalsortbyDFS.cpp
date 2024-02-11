#include <bits/stdc++.h> 
using namespace std;
void mapping(unordered_map<int,list<int>> &mp,vector<vector<int>> &edges)
{
    for(int i =0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
       // mp[v].push_back(u);
    }
}
void DFS(vector<bool> &visited,unordered_map<int,list<int>> &mp,vector<int> &ans,int node)
{
    visited[node] = true;
    

    for(auto i:mp[node])
    {
        if(!visited[i])
        {
            DFS(visited,mp,ans,i);
        }
    }
    ans.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<bool> visited(v);
    unordered_map<int,list<int>> mp;
    vector<int> ans;
    mapping(mp,edges);
    for(int i =0;i<v;i++)
    if(!visited[i])
    DFS(visited,mp,ans,i);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> vec = {{0,1},{0,3},{1,2},{3,2}};
    vector<int> ans = topologicalSort(vec,3,2);
    for(auto i:ans) cout<<i<<" ";
}