#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int distinctSubsequences(string s) 
{   long long mod = 1e9+7;
    // Write your code here.
    vector<long long> dp(s.length()+1,1);
    for(int i =0;i<s.length();i++)
    {   int j = i-1;
        while (j>=0)
        {
            if(s[j]==s[i]) break;
            j--;
        }
        if(j!=-1)
        dp[i+1] =(( (dp[i] *2)%mod) - dp[j])%mod;
        else dp[i+1] = (1ll*(dp[i]%mod)*2)%mod;
        dp[i+1] = dp[i+1]%mod;
    }
    int n = s.length();
   // return dp[s.length()];
    return dp[n]%mod>0?dp[n]%mod:dp[n]%mod+mod;
}
int main()
{
    string str = "pzetel";
    cout<<distinctSubsequences(str);
}