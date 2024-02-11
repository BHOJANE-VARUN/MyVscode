#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int> mp;
    for(int i =0;i<20;i++)
    {   int num = 1<<i;
        for(int k =0;k<n;k++)
        {
            mp[i] += (num&arr[k]);
        }
    }
    for(auto i:mp)
    {
        
        if(i.second%2==1 and (n-i.second)%2==1)
        {
            cout<<N<<endl;
            return;
        }
    }
    cout<<Y<<endl;
    return;
}
signed main()
{
test
{
    solve();
}
//dusro ka code copy karne se khar nahi chalta bhai
}