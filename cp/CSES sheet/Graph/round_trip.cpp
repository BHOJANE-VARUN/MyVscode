#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
int flag =0;
const int maxsize = 1e5;
vector<int> arr[maxsize];
bool vis[maxsize];
void dfshelper(int node,int p,vector<int>&ans)
{
	if(flag) return;
	vis[node] = true;
	ans.push_back(node);
    for(auto i:arr[node])
    {
    	if(flag) return;
       if(vis[i]==false)
       {
       		dfshelper(i,node,ans);
       }
       else if(i!=p)
       {
       		
       		int f = 0;
       		int cur =0;
    		for(auto j:ans)
    		{
    			if(j==i)
    			{
    				f = 1;
    				cout<<ans.size()+1-cur<<endl;
    			}
    			if(f==1) cout<<j+1<<" ";
    			cur++;
    		}
    		cout<<i+1<<endl;
    		flag =1;
    		return;
       }
    }
    ans.pop_back();
    return;
}
int n,m,u,v;
signed main()
{

    cin>>n>>m;
    for(int i =0;i<m;i++)
    {
    	cin>>u>>v;u--,v--;
    	arr[u].push_back(v);
    	arr[v].push_back(u);
    }
    vector<int> ans;
    for(int i =0;i<n;i++)
    {
    	if(!vis[i])
    	{
    		(dfshelper(i,-1,ans));
    	}
    }
    if(!flag)
    cout<<"IMPOSSIBLE"<<endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}