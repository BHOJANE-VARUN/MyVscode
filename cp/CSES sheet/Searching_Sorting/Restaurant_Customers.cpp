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
    set<pair<int,int>> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        st.insert({x,1});
        st.insert({y,-1});
    }
    int ans = INT_MIN;
    int ct =0;
    for(auto i:st)
    {
        ct += i.second;
        ans = max(ans,ct);
    }
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}