#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i =0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end());
    int ans =0;
    int t =0;
    for(int i =0;i<n;i++)
    {
        t += arr[i].first;
        ans += arr[i].second - t;
    }
    cout<<ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}
// 3
// 6 10
// 8 15
// 5 12