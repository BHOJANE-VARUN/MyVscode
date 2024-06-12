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
    // Function to return list containing vertices in Topological order.
    void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &sk)
    {
        vis[v] = true;
        for (auto i : adj[v])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, sk);
            }
        }
        sk.push(v);
    }
    string findOrder(string dict[], int N, int v)
    {
        vector<vector<int>> adj(v);
        for (int i = 0; i < N-1; i++)
        {

            for (int k = 0; k < min(dict[i].size(), dict[i+1].size()); k++)
            {
                if (dict[i][k] == dict[i+1][k])
                    continue;
                else
                {
                    int a = dict[i][k] - 'a', b = dict[i+1][k] - 'a';
                    adj[a].push_back(b);
                    break;
                }
            }
        }
        vector<bool> visit(v, false);
        stack<int> sk;
        for (int i = 0; i < v; i++)
        {
            if (!visit[i])
            {
                dfs(i, adj, visit, sk);
            }
        }
        string str = "";
        while (!sk.empty())
        {
            int num = sk.top();
            str +=  (num + 'a');
            sk.pop();
        }
        return str;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}
