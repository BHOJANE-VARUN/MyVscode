// #include<bits/stdc++.h>
// typedef long long int ll;
// #define Y "YES"
// #define N "NO"
// #define MODD 1000000007
// using namespace std;
// // void inputarrll(ll *arr,ll n)
// // {   ll temp;
// //     for(ll i =0;i<n;i++)
// //     {
// //         cin>>temp;
// //         arr[i] = temp;
// //     }
// // }
// int main()
// {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         unsigned long long int vec[3];
//         // vector<unsigned ll> vec(3);
//         for(int i =0;i<3;i++) cin>>vec[i];
//         sort(vec,vec+3);
//         ll mid = (vec[0]%MODD * (vec[1]-1)%MODD)%MODD;
//         ll ans = ((vec[2]-2)%MODD * mid)%MODD;
//         cout<<ans<<endl;
//     }

// }
#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MODD 1000000007
#define test int varun;cin>>varun;while(varun--)
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
    test
    {
        unsigned long long int vec[3];
        // vector<unsigned ll> vec(3);
        for(int i =0;i<3;i++) cin>>vec[i];
        sort(vec,vec+3);
        unsigned long long int mid = (vec[0]%MODD * ((vec[1]-1)%MODD * 1ll))%MODD;
        unsigned long long int  ans = ((vec[2]-2)%MODD * mid * 1ll)%MODD;
        cout<<ans<<endl;
    }

}