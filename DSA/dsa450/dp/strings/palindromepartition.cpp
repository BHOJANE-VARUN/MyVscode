#include <bits/stdc++.h> 
using namespace std;
unordered_map<string,int> mp;
int solve(string str,string com)
{   
    if(str==com) return 0;
    string key = str + " " + com;
   // if(mp.find(key)!=mp.end()) return mp[key];
    
    int ans =10000;
    int n = str.length();
    for(int i =1;i<str.length();i++)
    {
        int temp = 1 + solve(str.substr(0,i),com.substr(n-i)) + solve(str.substr(i),com.substr(0,n-i));
        ans = min(ans,temp);
    }
   // cout<<key<<" "<<mp[key]<<endl;
    //return mp[key] =ans;
    return ans;
}
int palindromePartitioning(string str)
{
    // Write your code here
    string com = str;
    reverse(com.begin(),com.end());
    return solve(str,com);
}
int main()
{
    string str = "aaccb";
    cout<<palindromePartitioning(str);
}
