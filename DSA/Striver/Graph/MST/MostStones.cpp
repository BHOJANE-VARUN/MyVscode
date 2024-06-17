#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
class DisjointSet {
    
public:
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row = 0,col=0;
        for(const auto &i:stones)
        {
            row = max(row,i[0]);
            col = max(col,i[1]);
        }
        DisjointSet obj(row+col+1);
        unordered_map<int,int> mp;
        for(const auto &i:stones)
        {
            int u = i[0];
            int v = i[1] + row+1;
            obj.unionByRank(u,v);
            mp[u] = 1;
            mp[v] = 1;
        }
        int cnt =0;
        for(const auto &i:mp)
        {
            if(obj.findUPar(i.first)==i.first)
                cnt++;
        }
        return stones.size()-cnt;
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}