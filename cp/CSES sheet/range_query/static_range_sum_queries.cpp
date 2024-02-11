#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const ll maxsize = 1e5;
//ll arr[maxsize+1];
#define test ll monu;cin>>monu;while(monu--)
using namespace std;
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
    ll n,q;
    cin>>n>>q;
    ll *arr = new ll[n];
    inputarrll(arr,n);
    ll *prefix = new ll[n+1];
    prefix[0] =0;
    for(ll i =1;i<n+1;i++)
    {
        prefix[i] = prefix[i-1]+ arr[i-1];
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
//dusro ka code copy karne se khar nahi chalta bhai
}