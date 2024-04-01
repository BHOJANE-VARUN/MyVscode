#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool pad(string &str)
{
    int i =0,j=str.length()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++,j--;
    }
    return true;
}
int solve(string &str,int s,vector<int> &dp)
{
    if(s==str.length())
        return 0;
    
    if(dp[s]!=-1)
        return dp[s];
    
    string cur = "";
    int ans = INT_MAX;
    for(int i = s;i<str.length();i++)
    {
        cur.push_back(str[i]);
        if(pad(cur))
        {
            int temp = 1 +  solve(str,i+1,dp);
            ans = min(ans,temp);
        }
    }
    return dp[s] =  ans;
}
int table(string &str)
{
    vector<int> dp(str.length()+1,INT_MAX);
    dp[str.length()] = 0;
    for(int i =str.length()-1;i>=0;i--)
    {
        string cur = "";
        int ans = INT_MAX;
        for(int j = i;j<str.length();j++)
        {
            cur.push_back(str[j]);
            if(pad(cur))
            {
                dp[i] = min(dp[i],dp[j+1]+1);
            }
        }
    }
    return dp[0];
}
int palindromePartitioning(string str)
{
  //  vector<int> dp(str.length()+1,-1);
    int ans = table(str);
    return ans-1;
}


signed main()
{

//dusro ka code copy karne se ghar nahi chalta bhai
}