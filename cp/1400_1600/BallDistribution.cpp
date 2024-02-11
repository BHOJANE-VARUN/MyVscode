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
        ll x,n;
        cin>>x>>n;
        vector<ll> vec;
        ll ct =0;
        for(ll i =0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            vec.push_back(temp);
            ct += temp;
        }
        cout<<max(ct-((x-1)*n*1ll),0ll)<<endl;
    }

}