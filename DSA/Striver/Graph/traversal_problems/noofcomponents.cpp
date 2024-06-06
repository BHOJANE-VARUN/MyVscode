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
    void dfshelper(int node, vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node] = 1;
        for (int i =0;i<n;i++)
        {
            if (adj[node][i] and !vis[i])
            {
                dfshelper(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt =0;
        for(int i =0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfshelper(i,isConnected,vis);
                i=0;
            }
        }
        return cnt;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}