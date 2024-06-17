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
    vector<int> rank, parent, size; 
public: 
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet obj(n*m);
        vector<vector<int>> arr(n,vector<int> (m,0));
        int dir[] = {0,1,0,-1,0};
        vector<int> ans;
        int cnt =0;
        for(auto it:operators)
        {
            int a = it[0],b = it[1];
            if(arr[a][b]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            arr[a][b] =1;
            cnt++;
            for(int i =0;i<4;i++)
            {
                int row = dir[i] + a;
                int col = dir[i+1] + b;
                if(row>=0 and col>=0 and row<n and col<m and arr[row][col]==1)
                {
                    if(obj.findUPar((row*m) + col)!=obj.findUPar((a*m)+b))
                    {
                        obj.unionByRank((row*m) + col,(a*m)+b);
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}