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
    	//Function to return list containing vertices in Topological order. 
    void dfs(int v,vector<vector<int>> &adj,vector<bool> &vis,unordered_map<int,bool> &sk)
    {
        vis[v] = true;
        for(auto i:adj[v])
        {
            if(mp.find(i)!=mp.end() and mp[i]==false)
            {
                mp[v] = false;
                return;
            }
            if(!vis[i])
            {
                dfs(i,adj,vis,sk);
            }
            else{
                mp[v] = false;
                return;
            }
        }
        mp[v] = true;
    }
	vector<int> topoSort(int V, vector<vector<int>> &adj) 
	{
	    vector<bool> visit(V,false);
        unordered_map<int,bool> sk;
        for(int i =0;i<V;i++)
        {
            if(!visit[i])
            {
                dfs(i,adj,visit,sk);
            }
        }
        vector<int> ans;
        for(auto i:sk)
        {
            if(i.second==true)
                ans.push_back(i.first);
        }
        return ans;
	}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return topoSort(graph.size(),graph);
    }
};
signed main()
{
    eventualSafeNodes(vector<vector<int>> ())
//dusro ka code copy karne se ghar nahi chalta bhai
}