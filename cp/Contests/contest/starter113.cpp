#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
pair<ll,ll> inputarrll(ll *arr,ll n)
{   ll temp;
    pair<ll,ll> pd = {INT_MIN,INT_MAX};
    ll pd.first = INT_MIN;
    ll mini = INT_MAX;
    for(ll i =0;i<n;i++)
    {
        cin>>temp;
        arr[i] = temp;
        pd.first = max(temp,pd.first);
        mini = min(temp,mini);
    }
    return {pd.first,mini};
}
int main()
{
    test
    {
       ll n;
       cin>>n;
       int m;
       cin>>m;
       ll *arr = new[n];
       pair<ll,ll> pd = inputarrll(arr,n);
       map<int,vector<int>> mp; 
       for(int i =0;i<n;i++) mp[arr[i]].push_back(i);
       int diff = pd.first-pd.second;
       int ans =diff;
        for(int i =1;i<mp[pd.second].size();i++)
        {
            if(mp[pd.second][i]-mp[pd.second][i-1]>m)
            {
                ans*=2;
            }
        }
        cout<<ans<<endl;
    }

//dusro ka code copy karne se khar nahi chalta bhai
}