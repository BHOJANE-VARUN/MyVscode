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
    ll *arr = new ll[n];
    inputarrll(arr,n);
    string str;
    cin>>str;
    int ans = INT_MAX;
    for(int i =0;i<str.length();i++)
    {
        if(str[i]=='0')
        {
            ans = min(ans,arr[i]);
        }
    }
    cout<<ans<<endl;
 }

//dusro ka code copy karne se khar nahi chalta bhai
}