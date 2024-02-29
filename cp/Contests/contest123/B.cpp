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
test
{
    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    int sum =0;
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      sum += arr[i];
    }
    sum *= 2;
    unordered_map<int,pair<int,int>> mp;
    for(int i =0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            mp[sum-(arr[i]+arr[j])] ={i,j};
        }
    }
    while(q--)
    {
        int cur;cin>>cur;
        if(mp.find(cur)==mp.end()) cout<<-1<<endl;
        else{
            cout<<arr[mp[cur].first]<<" ";
            for(int i =0;i<n;i++)
            {
                if(i!=mp[cur].first and i!=mp[cur].second)
                {
                    cout<<arr[i]<<" ";
                }
            }
            cout<<arr[mp[cur].second]<<endl;
        }
    }
}
//dusro ka code copy karne se khar nahi chalta bhai
}