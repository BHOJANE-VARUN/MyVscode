#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto &i:times)
        {
            adj[i[0]-1].emplace_back(i[1]-1,i[2]);
        }
        set<pair<int,int>> s;
        vector<int> ans(n,INT_MAX);
        s.insert({0,k-1});
        ans[k-1] = 0;
        while(s.size()) 
        {
            int cost = (*s.begin()).first,ele = (*s.begin()).second;
            s.erase(s.begin());
            for(auto i:adj[ele])
            {
                if(i.second+cost<ans[i.first])
                {
                    ans[i.first] = i.second + cost;
                    s.emplace(cost+i.second,i.first);
                }
                
            }
        } 
        int x=*ranges::max_element(ans);
        return x==INT_MAX? -1: x;
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}