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

int topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //vector<bool> visited(v);
    vector<int> ans;
    unordered_map<int,list<int>> mp;
    vector<int> indegree(v);
    mapping(mp,edges);
    for(auto i:mp)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    queue<int> que;
    for(int i =0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        ans.push_back(front);

        for(auto i:mp[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                que.push(i);
            }
        }
    }
    return ans.size();
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	int cnt = topologicalSort(edges,v,e);
    if(cnt!=v) return true;
    else return false;
}
int main()
{
    return 0;
}