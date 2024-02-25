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
    int n,x;
    cin>>n>>x;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    map<int,pair<int,int>> mp;

    for(int i =0;i<n;i++)
    {
        if(x!=0)
        mp[(arr[i]^x)].first++,mp[(arr[i]^x)].second++;
        mp[arr[i]].first++;
        //cout<<arr[i]<<" "<<mp[arr[i]].first<<" "<<mp[arr[i]].second<<endl;
        //cout<<(arr[i]^x)<<" "<<mp[arr[i]^x].first<<" "<<mp[arr[i]^x].second<<endl;
    }
    int ans =0;
    int num =0;
    for(auto i:mp)
    {
        if(ans<i.second.first)
        {
            ans = i.second.first;
            num = i.second.second;
        }
        else if(ans==i.second.first)
        {
            num = min(num,i.second.second);
        }
    }
    cout<<ans<<" "<<num<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}