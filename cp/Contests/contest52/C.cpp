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
    ll mini = arr[0];
    for(int i = 1;i<n;i++)
    {
        mini = __gcd(mini,arr[i]);
    }
    cout<<n*mini<<endl;
    
 }

//dusro ka code copy karne se khar nahi chalta bhai
}