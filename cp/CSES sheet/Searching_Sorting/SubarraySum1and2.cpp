#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
   return x ^ (x >> 31);
   }
   size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
   }
};
signed main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<int,int,custom_hash>mp;
    mp[0] =1;
    int sum =0,ans =0;
    int temp;
    for(int i =0;i<n;i++)
    {
      scanf("%lld",&temp);
      sum += temp;
        if(mp[sum-k])
        {
            ans += mp[sum-k];
        }
        mp[sum]++;
    }
    cout<<ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}