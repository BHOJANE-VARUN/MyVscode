#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(string &s,string &t,int i,int j)
{
    if(i==s.length()) return t.length()-j;
    if(j==t.length()) return s.length()-i;

    if(s[i]==t[j])
    {
        return solve(s,t,i+1,j+1);
    }
    else{
        int rep = 1 + solve(s,t,i+1,j+1);
        int delan = 1 + solve(s,t,i,j+1);
        int insans = 1 + solve(s,t,i+1,j);

        return min(rep,min(delan,insans));
    }
}
int solvemem(string &s,string &t,int i,int j,vector<vector<int>> &dp)
{
    if(i==s.length()) return t.length()-j;
    if(j==t.length()) return s.length()-i;

    if(dp[i][j]!=-1) return dp[i][j]; 

    if(s[i]==t[j])
    {
        return dp[i][j] = solvemem(s,t,i+1,j+1,dp);
    }
    else{
        int rep = 1 + solvemem(s,t,i+1,j+1,dp);
        int delan = 1 + solvemem(s,t,i,j+1,dp);
        int insans = 1 + solvemem(s,t,i+1,j,dp);

        return dp[i][j] = min(rep,min(delan,insans));
    }
}
// dp[i][j] means edit distance if we start a from i and b from j 
// base case if i==n then answer is len(b)-j and if j==m then answer is len(a)-i
// state change  if a[i]==b[j] then dp[i][j] = dp[i+1][j+1] else dp[i][j] = 1 +  min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))
// final ans dp[0][0]
int table(string &a,string &b)
{
    vector<vector<int>> dp(a.size()+1,vector<int> (b.size()+1,0));
    for(int i =0;i<=a.size();i++)
    {
        dp[i][b.size()] = a.size()-i;
    }
    for(int i =0;i<b.size();i++)
    {
        dp[a.size()][i] = b.size()-i;
    }

    for(int i = a.size()-1;i>=0;i--)
    {
        for(int j = b.size()-1;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 +  min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
            }
        }
    }
    return dp[0][0];
}
int tableopti(string &a,string &b)
{

   vector<int> prev(b.size()+1,0);
   vector<int> cur(b.size()+1,0);
    for(int i =0;i<=b.size();i++)
    {
        prev[i] = b.size()-i;
    }

    for(int i = a.size()-1;i>=0;i--)
    {
        cur[b.size()] = a.size()-i;
        for(int j = b.size()-1;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                cur[j] = prev[j+1];
            }
            else{
                cur[j] = 1 +  min(prev[j+1],min(prev[j],cur[j+1]));
            }
        }
        prev = cur;
    }
    return prev[0];
}
int editDistance(string &str1, string &str2)
{
    //write you code here
    // vector<vector<int>> dp(str1.length(),vector<int> (str2.length(),-1));
    // return solvemem(str1,str2,0,0,dp);
    return tableopti(str1,str2);

}
signed main()
{
    string a,b;
    cin>>a>>b;
    cout<<editDistance(a,b)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}