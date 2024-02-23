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
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      for(int j =0;j<31;j++)
      {
            mp[j]+= (((1ll<<j)&temp)>0);
           // cout<<(((1<<i)&temp)>0)<<" ";
      }
     // cout<<endl;
    }
    int maxi = 0;
    for(auto i:mp)
    {
        maxi = max(maxi,max(n-i.second,i.second));
    }
    cout<<maxi<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}