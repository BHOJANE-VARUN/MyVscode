#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
vector<int> bfstraversal(int v,vector<int> adj[])
{
    int vis[v] = {0};
    vis[0] = 1;
    queue<int> q;
    vector<int> bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return bfs;
}
void dfshelper(int node,vector<int> adj[],int vis[],vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfshelper(i,adj,vis,ls);
        }
    }
}
vector<int> dfstraversal(int v,vector<int> adj[])
{
    int vis[v] = {0};
    vector<int> dfs;
    dfshelper(0,adj,vis,dfs);
    return dfs;
}
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}