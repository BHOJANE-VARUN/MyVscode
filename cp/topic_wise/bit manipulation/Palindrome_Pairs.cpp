#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{

{
    int n;
    cin>>n;
    map<int,int> ct;
    int ans =0;
    for(int i =0;i<n;i++)
    {
        string temp;
        cin>>temp;
        int cur =0;
        for(auto i:temp)
        {
            cur = (cur^(1<<(i-'a')));
        }
        ans += ct[cur];
        for(int i =0;i<26;i++)
        {
            cur ^= (1ll<<i);
            ans += ct[cur];
            cur ^= (1ll<<i);
        }
        ct[cur]++;
    }
    cout<<ans<<endl;
//     unordered_map<int,int> mp;
//     for(auto i:arr)
//     {
//        // cout<<i<<endl;
//         mp[i]++;
//     }
//     int ans =0;
//     int ct =1;
//     int ct1 =0;
//     // for(auto i:mp)
//     // {
//     //     //cout<<i.first<<" "<<i.second<<endl;
//     //     if(__builtin_popcount(i.first)==1)
//     //     {
//     //         ct+=i.second;
//     //     }
//     //     if(i.first==0)
//     //     {
//     //         ct1 +=i.second;
//     //     }
//     //     if(i.second==1) continue;
//     //     ans += ((i.second*(i.second-1))/2);
//     // }
//     for(auto i:mp)
//     {
//         if(i.first==0)
//         {
//             ct = i.second;
//             continue;
//         }
//         if(__builtin_popcount(i.first)==1)
//         {
//             ans += ((i.second*(i.second-1))/2);
//             ct1 += i.second;
//         }
//     }
//     ans += ((ct*(ct-1))/2);
//     ans += ct1;
//    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}