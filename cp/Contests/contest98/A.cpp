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
    int n;
    cin>>n;
    vector<int> arr(1440,0);
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      arr[temp]++;
    }
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      arr[temp]++;
    }
    int ans =0;
    for(int i =0;i<1440;i++)
    {
        ans = max(ans,arr[i]);
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}