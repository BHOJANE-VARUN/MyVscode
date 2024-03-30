#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool solve(int i,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    if(k==0)
        return true;
    if(i==arr.size())
        return false;
    
    if(dp[i][k]!=-1)
        return dp[i][k];


    bool excl = solve(i+1,k,arr,dp);
    bool incl = false;
    if(k-arr[i]>=0)
    {
        incl = solve(i+1,k-arr[i],arr,dp);
    }
        
    
    return dp[i][k] =  excl or incl;
}
bool table(int k,vector<int> &arr)
{
    vector<vector<bool>> dp(arr.size()+1,vector<bool> (k+1,false));
    for(int i =0;i<=arr.size();i++)
        dp[i][0] = true;
    for(int i =1;i<=arr.size();i++)
    {
        for(int j =1;j<=k;j++)
        {
            dp[i][j] = dp[i][j] or dp[i-1][j];
            if(j-arr[i-1]>=0)
                dp[i][j] = dp[i][j] or dp[i-1][j-arr[i-1]];
        }
    }
    return dp[arr.size()][k];
}
bool subsetSumToK(int n, int k,vector<int> &arr) {
   // vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
   // return solve(0,k,arr,dp);
   return table(k,arr);
}
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<subsetSumToK(n,k,arr);
//dusro ka code copy karne se ghar nahi chalta bhai
}