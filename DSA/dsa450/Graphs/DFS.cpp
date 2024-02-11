#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
void mapping(unordered_map<int,list<int>> &mp,vector<vector<int>> &edges)
{
    for(int i =0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }
}
void DFS(unordered_map<int,bool> &visited,unordered_map<int,list<int>> &mp,vector<int> &ans,int node)
{
    visited[node] = true;
    ans.push_back(node);

    for(auto i:mp[node])
    {
        if(!visited[i])
        {
            DFS(visited,mp,ans,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> mp(E);
    mapping(mp,edges);
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    for(int i =0;i<E;i++)
    {
        if(!visited[i])
        {
            vector<int> temp;
            DFS(visited,mp,temp,i);
            ans.push_back(temp);
        }
    }
    return ans;
}
int main()
{
    return 0;
}