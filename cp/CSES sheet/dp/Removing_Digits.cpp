#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void countnum(int x,vector<bool> &cur)
{
    while(x!=0)
    {
        cur[x%10]=true;
        x = x/10;
    }
}
// int solve(int n,vector<int>& dp)
// {
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     if(n==0)
//     {
//         return 0;
//     }
//     set<int> st;
//     countnum(n,st);
//     int ans = INT_MAX;
//     for(auto i:st)
//     {
//         if(i!=0)
//         {
//             ans = min(ans,solve(n-i,dp))+1;
//         }
//     }
//     return dp[n] = ans;
// }
int solveit(int n)
{
    vector<int> dp(n+1,INT_MAX);
    dp[0] =0;
    for(int i =1;i<=n;i++)
    {
        vector<bool> st(10);
        countnum(i,st);
        for(int j=0;j<10;j++)
        {
            if(st[j] and i-j>=0)
            {
                dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
    }
    return dp[n];
}
signed main()
{
    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<solve(n,dp)<<endl; 
    cout<<solveit(n)<<endl; 
//dusro ka code copy karne se khar nahi chalta bhai
}