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
    bool bfstraversal(int v, vector<vector<int>> &adj,vector<int>&vis)
    {
        vis[v] = 0;
        queue<int> q;
        q.push(v);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : adj[node])
            {
                if (vis[i]==-1)
                {
                    vis[i] = (vis[node]==1?0:1);
                    q.push(i);
                }
                else if(vis[node]==vis[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> visit(graph.size(),-1);
        for(int i =0;i<graph.size();i++)
        {
            if(visit[i]==-1 and !bfstraversal(i,graph,visit))
            {
                return false;
            }
        }
        for(auto i:visit)
            cout<<i<<" ";
        cout<<endl;
        return true;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}