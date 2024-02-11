#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
#define test int monu;cin>>monu;while(monu--)
using namespace std;
const int maxisize = 100000;
ll power[maxisize+1];
void inputarrll(ll *arr,ll n)
{   ll temp;
    for(ll i =0;i<n;i++)
    {
        cin>>temp;
        arr[i] = temp;
    }
}
int main()
{
    power[0] =1;
    for(int i =1;i<=maxisize;i++)
    {
        power[i] = ((power[i-1] * 2) * 1ll)%MOD;
    }
    test
    {
       int n;
       cin>>n;
       unordered_map<ll,ll> mp;
       ll maxi = INT_MIN;
       for(int i =0;i<n;i++)
       {
            ll temp;
            cin>>temp;
            mp[temp]++;
            maxi = max(maxi,temp);
       }
       cout<<power[mp[maxi]]-1<<endl;
    }

//dusro ka code copy karne se khar nahi chalta bhai
}