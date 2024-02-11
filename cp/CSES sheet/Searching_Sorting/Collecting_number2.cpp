#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int compare(int old,int cur,int ele,map<int,int> &mp)
{
    if(ele==1)
    {
      return 0;
    }
    cout<<mp[ele-1]<<" "<<old<<" "<<cur<<" "<<ele<<endl;
    if(mp[ele-1]<old and mp[ele-1]>=cur) return 1;
    else if(mp[ele-1]>old and mp[ele-1]<=cur) return -1;
    else return 0;
}
signed main()
{
    int n,q;
    cin>>n>>q;
    map<int,int> mp;
    int ans =0;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      arr[i] = temp;
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
    ans++;
    while (q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<ans<<endl;
        ans += compare(a,b,arr[a-1],mp);
       // cout<<ans<<endl;
        ans += compare(b,a,arr[b-1],mp);
       // cout<<ans<<endl;
        swap(arr[a-1],arr[b-1]);
        swap(mp[arr[a-1]],mp[arr[b-1]]);
       // for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;
        cout<<ans<<endl;
    } 
    // 4 2 1 5 3
    // 4 1 2 5 3 = 2
    // 3 1 2 5 4 = 

//dusro ka code copy karne se khar nahi chalta bhai
}