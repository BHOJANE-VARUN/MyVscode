#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
//O(NlogN) complexity of following code======
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int,int>>> adj(n);
//         for(auto i:flights)
//         {
//             adj[i[0]].push_back({i[1],i[2]});
//         }
//         set<pair<int,pair<int,int>>> s;
//         vector<int> ans(n,INT_MAX);
//         s.insert({0,{0,src}});
//         ans[src] =0;
//         while(s.size()) 
//         {
//             int cnt = (*s.begin()).first,cost = (*s.begin()).second.first,ele = (*s.begin()).second.second;
//             s.erase(s.begin());
//             if(cnt==k+1)
//                 continue;
//             for(auto i:adj[ele])
//             {
//                 if(i.second+cost<ans[i.first])
//                 {
//                     ans[i.first] = i.second + cost;
//                     s.insert({cnt+1,{cost+i.second,i.first}});
//                 }
                
//             }
//         }
//         for(auto i:ans) cout<<i<<" ";
//         cout<<endl;
//         return ans[dst]==INT_MAX?-1:ans[dst];
//     }
// };
//O(n) time complexity solution ===
class Solution {
public:
//  T.C. : O(no. of edges) = O(flights.size())
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int,pair<int,int>>> q; // stops, node, dist
        q.push({0,{src, 0} });
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k ) continue;
            for(auto p: adj[node]){
                int adjN = p.first;
                int edW = p.second;
                if(cost + edW < dist[adjN] && stops <= k){
                    dist[adjN] = cost + edW;
                    q.push({stops+1, {adjN, cost + edW}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}