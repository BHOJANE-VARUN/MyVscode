#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
class Solution
{
public:
    void dfshelper(int node, vector<vector<int>> &adj, vector<int> &cost)
    {
        //cout<<node<<endl;
       // int ele = -1,mini = INT_MAX;
      // vis[node] = true;
        for (auto i : adj[node])
        {
            if (i!=node)
            {
                int a = cost[i]==-1?INT_MAX:cost[i];
               if(a>cost[node]+1)
               {
                    cost[i] = cost[node] + 1;
                    dfshelper(i,adj,cost);
               }
              // if(!vis[i])
               
            }
        }
       // vis[node] = false;
            
    }
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> cost(N,-1);
        vector<vector<int>> adj(N);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
       // vector<bool> visit(N,false);
        cost[src] = 0;
        dfshelper(src,adj,cost);
        return cost;
    }
};
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> cost(N,INT_MAX);
        vector<vector<int>> adj(N);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        set<pair<int,int>> s;
        cost[src] =0;
        s.insert({0,src});
        while (s.size())
        {
            int co = (*s.begin()).first,ele = (*s.begin()).second;
            s.erase(s.begin());
            for(auto i:adj[ele])
            {
                if(cost[i]>co+1)
                {
                    cost[i] = co+1;
                    s.insert({cost[i],i});
                }
            }
        }
        for(int i =0;i<N;i++)
        {
            if(cost[i]==INT_MAX)
            {
                cost[i] = -1;
            }
        }
        return cost;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}