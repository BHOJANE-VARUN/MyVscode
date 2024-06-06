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
test
{
    vector<pair<int,int>> arr;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    int ans = arr[n-2].first*arr[n-1].second + arr[n-1].first*arr[n-2].second;
    cout<<ans<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}