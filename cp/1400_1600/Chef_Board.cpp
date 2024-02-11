#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
// void inputarrll(ll *arr,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int i =1;
        ll ans = 0;
        while(i<=n)
        {
            ll cur = n-i+1;
            ans += cur*cur;
            i+=2;
        }
        cout<<ans<<endl;
    }

}