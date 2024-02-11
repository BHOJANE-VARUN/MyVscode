#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
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
test
{
    ll n;
    cin>>n;
    ll* arr = new ll[n];  
    inputarrll(arr,n);
    unordered_map<int,int> mp;
    for(int i =0;i<n;i++) mp[arr[i]]++;
    int ct =0;
    for(auto i:mp) ct+= i.second;
    if(ct%2) cout<<N<<endl;
    else cout<<Y<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}