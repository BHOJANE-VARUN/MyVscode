#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
void mappingDirected(unordered_map<int,list<int>> &mp,vector<vector<int>> &edges)
{
    for(int i =0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
       // mp[v].push_back(u);
    }
}
bool checkcyclicDFS(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &DFSvisited,int node)
{
    visited[node] = 1;
    DFSvisited[node] =1;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
           bool ans = checkcyclicDFS(adj,visited,DFSvisited,i);
           if(ans) return ans;
        }
        else if(DFSvisited[node])
        {
            return true;
        }
    }
    DFSvisited[node] =0;
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	unordered_map<int,list<int>> adj;
    mappingDirected(adj,edges);
    unordered_map<int,bool> visited;
    unordered_map<int,bool> DFSvisited;
    for(auto i:adj)
    {
        if(!visited[i.first])
        {
            bool ans =checkcyclicDFS(adj,visited,DFSvisited,i.first);
            if(ans) return ans;
        }
    }
    return false;
}
