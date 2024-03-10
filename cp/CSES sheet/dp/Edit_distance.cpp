#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp)
{   
    if(i==-1)
    {
        return j+1;
    }
    if(j==-1)
    {
        return i+1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j] = solve(i-1,j-1,a,b,dp);
    }
    int repla = solve(i-1,j-1,a,b,dp)+1;
    int ad = solve(i,j-1,a,b,dp)+1;
    int remov = solve(i-1,j,a,b,dp)+1;
    return dp[i][j] =  min(repla,min(ad,remov));
}
// what are overlapping problems?
// if we see sufix then basic inuition is 
// if we do any changes at ith index then it effect i+1th suffix
// so at any index I can do add,remove and replace 
// so if we go from n-1 to 0 then 
// dp[i][j] = edit distance between last i of a string and last j elements of b string
// transition state 
// dp[i][j] = min of dp[i+1][j] and dp[i][j+1] and dp[i+1][j+1] + 1
// if a[i]==b[j] then dp[i][j] = dp[i+1][j+1] 
// base case 
// 
int solveit(string &a,string &b)
{
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i =1;i<=a.size();i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0;i<=b.size();i++)
    {
        dp[0][i] = i;
    }
    for(int i =1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            char x = a[i-1];char y = b[j-1];
            if(x==y)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j-1]+1;
            }
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        }
    }
    return dp[a.size()][b.size()];
}
signed main()
{
    string a,b;
    cin>>a>>b;
    //vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
    //cout<<solve(a.size()-1,b.size()-1,a,b,dp)<<endl;
    cout<<solveit(a,b)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}