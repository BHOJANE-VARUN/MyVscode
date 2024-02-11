#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
using namespace std;
int arr[200000];
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
        for(int i =0;i<200000;i++) arr[i] =0;
        int n;
        cin>>n;
        ll temp;
        for(ll i =0;i<n;i++)
        {
            cin>>temp;
            arr[temp]++;
        }
        ll ans =0;
        int prev = 1;
        for(int i=1;i<200000;i++)
        {
            if(arr[i]==0) break;
            //cout<<i<<arr[i]<<endl;
            prev = prev*arr[i];
            //cout<<temp<<endl;
            ans += prev;
        }
        cout<<ans<<endl;
    }

}