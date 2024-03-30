#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int i,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i==arr.size()+1)
        return 0;
    if(k==0)
        return 0;
    
    if(dp[i][k]!=-1)
        return dp[i][k];


    int excl = solve(i+1,k,arr,dp);
    int incl = 0;
    if(k-i>=0)
    {
        incl = arr[i-1] + solve(i,k-i,arr,dp);
    }
        
    
    return dp[i][k] =  max(excl,incl);
}

int table(vector<int> &arr,int n)
{
   vector<vector<int>> dp(n+2,vector<int> (n+2,0));
   for(int i = 1;i<=n;i++)
   {
        for(int j = 1;j<=n;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=i)
                dp[i][j] = max(dp[i][j],dp[i][j-i] + arr[i-1]);
        }
   }
   return dp[n][n];
}
int cutRod(vector<int> &price, int n)
{
    // vector<vector<int>> dp(n+2,vector<int> (10000,-1));
	// return solve(1,n,price,dp);
    return table(price,n);
}

signed main()
{
    
//dusro ka code copy karne se ghar nahi chalta bhai
}