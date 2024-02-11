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
    int n;
    cin>>n;
    map<int,int> mp;
    int ans =0;
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      mp[temp] =i+1;
    }
    int prev =0;
    for(auto i:mp)
    {
        if(prev>i.second)
        {
          ans++;
        }
        prev = i.second;
    }
    cout<<ans+1<<endl; 
//dusro ka code copy karne se khar nahi chalta bhai
}