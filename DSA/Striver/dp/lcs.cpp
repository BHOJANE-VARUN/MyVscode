#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp)
{
    if(i==a.size() or j==b.size())
    {
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j])
        return 1 + solve(a,b,i+1,j+1,dp);
    
    int lef = solve(a,b,i+1,j,dp);
    int rig = solve(a,b,i,j+1,dp);
    return dp[i][j] =  max(lef,rig);
}
// stage = dp[i][j] maximum ans if we start from i and j indexes
// increment dp[i][j] = max(dp[i+1][j],dp[i][j+1]) if a[i]!=b[i] else 1 + dp[i+1][j+1]
// base case dp[n][j] = dp[i][m] = dp[n][m] = 0
// final ans dp[0][0] 
int solveit(string &a,string &b)
{
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i = a.size()-1;i>=0;i--)
    {
        for(int j = b.size()-1;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}
signed main()
{

    string a,b;
    cin>>a>>b;
    //vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
    cout<<solveit(a,b)<<endl;

//dusro ka code copy karne se ghar nahi chalta bhai
}