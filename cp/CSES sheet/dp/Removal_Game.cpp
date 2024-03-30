#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void print(vector<vector<int>> &dp)
{
    for(auto i:dp)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int solve(int f,int *arr,int i,int j,vector<vector<vector<int>>> &dp)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][f]!=-1)
    {
        return dp[i][j][f];
    }
    if(f==0)
    {
        int lef = arr[i] + solve(1,arr,i+1,j,dp);
        int rig = arr[j] + solve(1,arr,i,j-1,dp);
        return dp[i][j][f] =  max(lef,rig);
    }
    else{
        int lef = arr[i] + solve(1,arr,i+1,j,dp);
        int rig = arr[j] + solve(1,arr,i,j-1,dp);
        if(lef>rig)
        {
            return dp[i][j][f] =  solve(0,arr,i+1,j,dp);
        }
        else{
            return dp[i][j][f] =  solve(0,arr,i,j-1,dp);
        }
    }
}
int solveit(int *arr,int n)
{
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i =0;i<n;i++) dp[i][i] = arr[i];
    for(int i = n-1;i>=0;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            int lef =0;
            int rig = 0;
            int cen =0;
            if(i+2<n)
                lef = dp[i+2][j] + arr[i];
            if(j-1>=0)
                rig = dp[i+1][j-1] + max(arr[i],arr[j]);
            if(j-2>=0) 
                cen = dp[i][j-2] + arr[j];
            dp[i][j] = max(min(lef,rig),min(rig,cen));
        }
        print(dp);
    }
    return  dp[0][n-1];
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
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int>(2,-1)));
    int ans = solve(0,arr,0,n-1,dp);
   // dp[i][j] = max of min of dp[i+2][j],dp[i+1][j-1],min of dp[i+1][j-1],dp[i][j-2]
   // int ans = solveit(arr,n);
    cout<<ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}