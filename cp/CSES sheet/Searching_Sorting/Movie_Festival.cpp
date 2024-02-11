#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int>&b)
{
    if(a.first<b.first) return true;
    else if(a.first==b.first) return a.second<b.second; 
    else return false;
}
signed main()
{
    vector<pair<int,int>> mp;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        mp.push_back({b,a});
    }
    sort(mp.begin(),mp.end(),comp);
    int cur =0;
    int ans =0;
    for(auto i:mp)
    {
        if(cur<=i.second)
        {
            cur = i.first;
            ans++;
        }
    }
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}