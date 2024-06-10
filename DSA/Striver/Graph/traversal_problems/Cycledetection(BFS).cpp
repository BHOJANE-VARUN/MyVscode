#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    // store <source node, parent node>
    queue<pair<int, int>> q;
    q.push({src, -1});
    // traverse until queue is not empty
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // go to all adjacent nodes
        for (auto adjacentNode : adj[node]) {
            // if adjacent node is unvisited
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if adjacent node is visited and is not its own parent node
            else if (parent != adjacentNode) {
                // yes, it is a cycle
                return true;
            }
        }
    }
    // there's no cycle
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // initialise them as unvisited
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis))
                return true;
        }
    }
    return false;
}

signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}