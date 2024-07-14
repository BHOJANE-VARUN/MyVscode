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
const int mXn = 1e5;
vector<int> arr[mXn],ans;
int n,m;
int a,b;
int ele;
int cur;
signed main()
{
	cin>>n>>m;
	vector<int> p(n,-1);
	for(int i =0;i<m;i++)
	{
		cin>>a>>b;a--,b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	//for(int i =0;i<n;i++) cout<<p[i]<<" ";
	queue<int> q;
	q.push(0);
	while(q.size())
	{
		ele = q.front();q.pop();
		if(ele==n-1)
		{
			//something
			cur = ele;
			while(cur!=0)
			{
				ans.push_back(cur);
				cur = p[cur];
			}
			ans.push_back(0);
			cout<<ans.size()<<endl;
			for(int i =ans.size()-1;i>=0;i--) cout<<ans[i]+1<<" ";
			//for(int i =0;i<n;i++) cout<<p[i]<<" ";
			 return 0;
		}
		for(auto i:arr[ele])
		{
			if(p[i]==-1)
			{
				p[i] = ele;
				q.push(i);
			}
			
		}
	}
	
	cout<<"IMPOSSIBLE"<<endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}