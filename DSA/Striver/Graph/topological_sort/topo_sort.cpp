#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
    void dfs(int v,vector<int> &adj,vector<bool> &vis,stack<int> &sk)
    {
        vis[v] = true;
        for(auto i:adj[v])
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,sk);
            }
        }
        sk.push(v);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visit(V,false);
        stack<int> sk;
        for(int i =0;i<V;i++)
        {
            if(!visit[i])
            {
                dfs(i,adj,visit,sk);
            }
        }
        vector<int> ans;
        while(!sk.empty())
        {
            ans.push_back(sk.top());
            sk.pop();
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