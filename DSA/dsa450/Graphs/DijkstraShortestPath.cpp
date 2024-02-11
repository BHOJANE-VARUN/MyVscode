#include <bits/stdc++.h> 
using namespace std;
 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> mp;
    for(int i =0;i<vec.size();i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wei = vec[i][2];

        mp[u].push_back({v,wei});
        mp[v].push_back({u,wei});
    }

    set<pair<int,int>> pq;
    pq.insert({0,source});
    vector<int> ans(vertices,INT_MAX);
    ans[source] = 0;
    while (!pq.empty())
    {
        pair<int,int> i = *pq.begin();
        pq.erase(pq.begin());
        for(auto ele:mp[i.second])
        {
          
            if(ans[ele.first]>i.first+ele.second)
            {
                auto it = pq.find({ans[ele.first],ele.first});
                if(it!=pq.end())
                {
                    pq.erase(it);
                }
                ans[ele.first] = i.first + ele.second;
                pq.insert({i.first + ele.second,ele.first});
            }
        }
    }
    return ans;
}
int main(){ return 0; }