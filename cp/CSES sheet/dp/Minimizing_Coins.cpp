#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int x,int *arr,int n,unordered_map<int,int> &mp)
{
    if(mp[x]!=0)
    {
        return mp[x];
    }
    if(x<0)
    {
        return 10000000;
    }
    if(x==0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for(int i =0;i<n;i++)
    {
        int cur = solve(x-arr[i],arr,n,mp)+1;
        ans = min(ans,cur); 
    }
    return mp[x] = ans;
}
int solvemem(int x,int *arr,int n)
{
    vector<int> dp(x+1);
    for(int i =1;i<x+1;i++)
    {
        int ans = INT_MAX;
        for(int j =0;j<n;j++)
        {
            if(i-arr[j]==0)
            {
                ans = min(ans,dp[i-arr[j]]+1ll);
            }
        }
        dp[i] = ans;
    }
    return dp[x];
}
signed main()
{
    int n,x;
    cin>>n>>x;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    // unordered_map<int,int> mp;
    // int ans = solve(x,arr,n,mp);
    int ans = solvemem(x,arr,n);
    if(ans>x)
    {
        cout<<-1<<endl;
    }
    else
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}