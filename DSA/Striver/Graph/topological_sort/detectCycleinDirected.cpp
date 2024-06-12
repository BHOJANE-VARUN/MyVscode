//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void dfs(vector<int> adj[],int src,int v,vector<int> &vis,bool &f)
    {
        if(f==1)
            return;
        vis[v] = src;
        for(auto i:adj[v])
        {
            if(vis[i]!=-1 and vis[i]==src)
            {
                f =1;
                return;
            }
            else if(vis[i]==-1)
            {
                dfs(adj,src,i,vis,f);
            }
        }
        vis[v] = -2;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visit(V,-1);
        bool f= false;
        for(int i =0;i<V;i++)
        {
            if(visit[i]==-1)
            {
                dfs(adj,i,i,visit,f);
            }
            if(f)
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends