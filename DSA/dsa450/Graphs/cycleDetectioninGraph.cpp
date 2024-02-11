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
bool cyclefinderDFS(unordered_map<int,bool> &visited,int parent,unordered_map<int,list<int>> &mp,int node)
{
    visited[node] = true;

    for(auto i:mp[node])
    {
        if(!visited[i])
        {
            bool temp = cyclefinderDFS(visited,node,mp,i);
            if(temp)
            {
                return true;
            }
        }
        else if(parent!=i){
            return true;
        }
    }

    return false;
}
bool cyclefindeBFS(unordered_map<int,bool> &visited,unordered_map<int,list<int>> &mp,unordered_map<int,int> &parent,int node)
{
    queue<int> que;
    que.push(node);
    parent[node] = -1;
    visited[node] = true;
    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        for(auto i:mp[top])
        {
            if(!visited[i])
            {
                parent[i] = top;
                visited[i] = true;
                que.push(i);
            }
            else if(parent[top]!=i)
            {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,bool> visited;
    //unordered_map<int,int> parent;
    unordered_map<int,list<int>> mp;
    unordered_map<int,int> parent;
    mapping(mp,edges);
    for(auto i:mp)
    {
        if(!visited[i.first])
        {
           // bool ans = cyclefinder(visited,-1,mp,i.first);
           bool ans = cyclefindeBFS(visited,mp,parent,i.first);
            if(ans)
            {
                return "YES";
            }
        }

    }
    return "NO";
}
int main()
{
    return 0;
}
