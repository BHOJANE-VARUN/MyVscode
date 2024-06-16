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
int prim(int v, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> p;
    int ans = 0;
    p.push({0, 0});
    vector<bool> visit(v, false);
    while (!p.empty())
    {
        int cost = p.top().first, ele = p.top().second;
        p.pop();
        if (visit[ele])
            continue;
        ans += cost;
        visit[ele] = 1;
        for (auto i : adj[ele])
        {
            int v = i[0];
            int w = i[1];
            if (!visit[v])
                p.push({w, v});
        }
    }
    return ans;
}
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}