#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int i,int prev,int *arr,int n,vector<vector<int>> &dp)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i][prev]!=-1) return dp[i][prev];
    int ans = 0;
    if(prev<arr[i])
    {
        ans = max(ans,solve(i+1,arr[i],arr,n,dp)+1);
    }
    ans = max(ans,solve(i+1,prev,arr,n,dp));
    return dp[i][prev] =  ans;
}
// dp[i][prev] tell us that lcs can be made by using n-i elements and start with prev
// we need  dp[i+1][prev] and dp[i+1][arr[i]]
// dp[i][prev] = max of  dp[i+1][prev],dp[i+1][arr[i]]
// base case that lcs can made by i==n-1 is one if prev<arr[i] and zero if prev>arr[i]
int lis(int arr[], int n)
{
    int lis[n];
 
    lis[0] = 1;
 
    // Compute optimized LIS values in
    // bottom up manner
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}
int lisop(int a[],int n) {
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
signed main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
   // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
   // cout<<solve(0,0,arr,n,dp);
   cout<<lisop(arr,n);
//dusro ka code copy karne se ghar nahi chalta bhai
}