#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// class DisjointSet {
    
// public:
//     vector<int> rank, parent, size; 
//     DisjointSet(int n) {
//         rank.resize(n+1, 0); 
//         parent.resize(n);
//         size.resize(n+1); 
//         for(int i = 0;i<n;i++) {
//             parent[i] = i; 
//             size[i] = 1; 
//         }
//     }

//     int findUPar(int node) {
//         if(node == parent[node])
//             return node; 
//         return parent[node] = findUPar(parent[node]); 
//     }

//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u); 
//         int ulp_v = findUPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//         }
//         else if(rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u; 
//         }
//         else {
//             parent[ulp_v] = ulp_u; 
//             rank[ulp_u]++; 
//         }
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u); 
//         int ulp_v = findUPar(v); 
//         if(ulp_u == ulp_v) return; 
//         if(size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v; 
//             size[ulp_v] += size[ulp_u]; 
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v]; 
//         }
//     }
// }; 
// vector<int> krushal(int v,vector<vector<int>>& edges)
// {
//     // vector<pair<int,pair<int,int>>> edges;
//     // for(int i =0;i<v;i++)
//     // {
//     //     for(auto it:adj[i])
//     //     {
//     //         int v = it[0];
//     //         int cost = it[1];
//     //         int u = i;
//     //         if(u<v)
//     //             edges.push_back({cost,{u,v}});
//     //     }
//     // }
//     //sort(edges.begin(),edges.end());
//    // int ans =0;
//     DisjointSet obj(v);
//     for(auto i:edges)
//     {
//        // int cost = i.first,u = i.second.first,v = i.second.second;
//        int u = i[0],v = i[1];
//         if(obj.findUPar(u)!=obj.findUPar(v))
//         {
//            obj.unionByRank(u,v); 
//           // ans += i.first;
//         }
//     }
//     for(int i =0;i<v;i++)
//        obj.parent[i] =  obj.findUPar(i);
//     return obj.parent;
// }
// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if(connections.size()<n-1)
//             return -1;
//         vector<int> ans = krushal(n,connections);
//         unordered_map<int,int> mp;
//         for(auto i:ans)
//             mp[i]++;
//         for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;
//         return mp.size()-1;
//     }
// };

void dfshelper(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto i:adj[node])
    {
        if (!vis[i])
        {
            dfshelper(i, adj, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfshelper(i, isConnected, vis);
        }
    }
    return cnt;
}
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if(connections.size()<n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return findCircleNum(adj)-1;
    }
};