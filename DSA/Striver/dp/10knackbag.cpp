#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int i,vector<int> &a,vector<int>&b,int w,vector<vector<int>> &dp)
{
    if(i==a.size() or w==0)
    {
        return 0;
    }
    if(dp[i][w]!=-1)
      return dp[i][w];

    int excl = solve(i+1,a,b,w,dp);
    int incl =0;
    if(w>=a[i])
    {
        incl = b[i] + solve(i+1,a,b,w-a[i],dp);
    }
    return dp[i][w] =  max(incl,excl);
}
int solveit(vector<int> &wei,vector<int>&val,int w)
{
    int n = wei.size();
    vector<vector<int>> dp(n+1,vector<int> (w+1,0));
    for(int i =0;i<=w;i++)
    {
        if(i>=wei[0])
        {
            dp[0][i] = val[0];
        }
    }
    for(int i =1;i<n;i++)
    {
        for(int j = 1;j<=w;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(wei[i]<=j)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-wei[i]]+val[i]);
            }
        }
    }
    return dp[n-1][w];
}
signed main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
    {
      cin>>a[i];
    }
    vector<int> b(n);
    for(int i =0;i<n;i++)
    {
      cin>>b[i];
    }
    int w;cin>>w;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
    cout<<solveit(a,b,w)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}