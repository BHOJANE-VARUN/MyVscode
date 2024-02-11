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
    set<int> arr;
    arr.insert(0);
    int x,n;
    cin>>x>>n;
    arr.insert(x);
    map<int,int> mp;
    mp[x] =1;
    for(int i =0;i<n;i++)
    {
        int temp;
        cin>>temp;
        auto it = arr.lower_bound(temp);
        int r = *it;
        --it;
        int l = *it;
        --mp[r-l];
        if(!mp[r-l]) mp.erase(r-l);
        mp[r-temp]++;
        mp[temp-l]++;
        arr.insert(temp);
        cout<<(--(mp.end()))->first<<" ";
    }
//dusro ka code copy karne se khar nahi chalta bhai
}