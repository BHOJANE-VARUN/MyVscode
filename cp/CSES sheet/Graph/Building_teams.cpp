#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
int n,m;
int u,v;
bool dfshelper(int node,vector<vector<int>> &adj,vector<int> &p)
{
    for(auto i:adj[node])
    {
        if(p[i]==-1)
        {
        	p[i] = p[node]^1;
            if(dfshelper(i,adj,p)==false) return false;
        }
        else{
        	if(p[i]==p[node])
        	{
        		//cout<<i+1<<" "<<node+1<<endl;
        		return false;
        	}
        }
        
    }
    return true;
}
signed main()
{
	cin>>n>>m;
	vector<int> p(n,-1);
	vector<vector<int>> adj(n);
	for(int i =0;i<m;i++)
	{
		cin>>u>>v;u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i =0;i<n;i++)
	{
		if(p[i]==-1)
		{
			p[i] = 0;
			if(dfshelper(i,adj,p)==false)
			{
				//for(auto i:p) cout<<i<<" ";
				//	cout<<endl;
				cout<<"IMPOSSIBLE"<<endl;
				return 0;
			}
		}
	}
	for(int i =0;i<n;i++)
	{
		cout<<p[i]+1<<" ";
	}
    // dusro ka code copy karne se ghar nahi chalta bhai
}