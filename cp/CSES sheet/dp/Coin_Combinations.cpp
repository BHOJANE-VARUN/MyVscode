#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int *arr,int n,int x,unordered_map<int,int> &mp)
{
    if(mp.find(x)!=mp.end())
    {
        return mp[x];
    }
    if(x==0) return 1;
    int ans =0;
    for(int i =0;i<n;i++)
    {
        if(x-arr[i]>=0)
        {
            ans += solve(arr,n,x-arr[i],mp);
        }
    }
    return mp[x] =  ans;
}
int solveit(int *arr,int n,int x)
{
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i =1;i<=x;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i-arr[j]>=0)
            {
                dp[i] = (dp[i] + dp[i-arr[j]])%MOD;
            }
        }
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
    unordered_map<int,int> mp;
    //int ans = solve(arr,n,x,mp);
    int ans = solveit(arr,n,x);
    cout<<ans<<endl;

//dusro ka code copy karne se khar nahi chalta bhai
}