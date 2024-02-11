#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
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
// ll t;
// cin>>t;
// while (t--)
// {
//     /* code */
// }
    int x=1,n=3;
    cin>>x>>n;
    ll ans =0;
    vector<int> vec = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
    for(int i =0;i<n;i++)
    {
        string temp;
        cin>>temp;
        int low = 3,high = 52;
        while (low<high)
        {
            int cur =0;
            cur += temp[low-3]-'0';
            cur += temp[low-2]-'0';
            cur += temp[low-1]-'0';
            cur += temp[low]-'0';
            cur += temp[high]-'0';
            cur += temp[high+1]-'0';
            low+=4;
            high-=2;
            cur = 6-cur;
            if(cur<x)
            {
                continue;
            }
            else{
                ans += (vec[cur]/(vec[x]*vec[cur-x]));
            }
        }
        
    }
    cout<<ans<<endl;
}