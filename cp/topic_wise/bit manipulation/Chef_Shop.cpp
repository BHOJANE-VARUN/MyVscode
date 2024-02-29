// #include<bits/stdc++.h>
// #define int long long int
// #define Y "YES"
// #define N "NO"
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// signed main()
// {
// test
// {
//     int n,k;
//     cin>>n>>k;
//     map<float,pair<int,int>> mp;
//     for(int i=0;i<n;i++)
//     {
//         float a,b;
//         cin>>a>>b;
//         float cur = b/a;
//         mp[cur].first = a;
//         mp[cur].second = b;
//     }
//     auto it = --mp.end();
//     int ans =0;
//     while(it!=mp.begin() and k)
//     {
        
//         if(k>=it->second.first)
//         {
//             ans += it->second.second;
//             k -= it->second.first;
//         }
//         it--;
//     }
//     if(k)
//     {
//         if(k>=it->second.first)
//         {
//             ans += it->second.second;
//             k -= it->second.first;
//         }
//     }
//     cout<<ans<<endl;
// }
// //dusro ka code copy karne se khar nahi chalta bhai
// }
#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(vector<pair<int,int>> &arr,int i,int k)
{
    if(i==arr.size() or k<=0)
    {
        return 0;
    }

    if(k>=arr[i].first)
    {
        int incl = solve(arr,i+1,k-arr[i].first)+arr[i].second;
        int excl = solve(arr,i+1,k);
        return max(incl,excl);
    }
    else{
        return solve(arr,i+1,k);
    }
}
signed main()
{
test
{
    vector<pair<int,int>> arr;
    int n,k;
    cin>>n>>k;
    for(int i =0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    cout<<solve(arr,0,k)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}