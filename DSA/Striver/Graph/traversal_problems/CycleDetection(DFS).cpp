#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool detect(int src,int i, vector<int> adj[], int vis[]) {
    vis[i] = 1;
    for(auto adjacentNode: adj[i]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(detect(i,adjacentNode,adj,vis) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != src) return true;   
    // there's no cycle
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // initialise them as unvisited
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(-1,i, adj, vis))
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