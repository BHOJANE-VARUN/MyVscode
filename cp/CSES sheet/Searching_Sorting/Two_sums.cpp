#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{
    int n,m;
    cin>>n>>m;
    int *arr = new int[n];
    map<int,int> mp;
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      if(mp.find(m-arr[i])!=mp.end())
      {
        cout<<i+1<<" "<<mp[m-arr[i]]<<endl;
        return 0;
      }
      mp[arr[i]] = i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}