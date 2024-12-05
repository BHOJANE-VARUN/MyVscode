#include<bits/stdc++.h>
// #define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int solve(string cur,unordered_map<string,vector<vector<string>>> &mp,unordered_map<string,int>&dp)
{
    if(mp.find(cur)==mp.end())
    { 
        return 1;
    }
    if(dp.find(cur)!=dp.end())
        return dp[cur];
    int ans = 10000000;
    for(auto i:mp[cur])
    {
        int cur =0;
        for(auto j:i)
        {
           cur +=  solve(j,mp,dp);
        }
        ans = min(ans,cur);
    }
    return dp[cur] =  ans;
}
void splitting(vector<string> &temp,string &str)
{
    unsigned int i =0;
    string cur = "";
    while (i<str.size())
    {
        if(str[i]=='+')
        {
            temp.push_back(cur);
            cur = "";
        }
        else
           cur.push_back(str[i]);
        i++;
    }
    temp.push_back(cur);
}
signed main()
{
    int n;cin>>n;
    unordered_map<string,vector<vector<string>>>mp;
    unordered_map<string,int> dp;
    while(n--)
    {
        string str;cin>>str;
        unsigned int temp =0;
        string keys;
        while(str[temp]!='=')
        {
            keys.push_back(str[temp]);
            temp++;
        }
        string values;
        temp++;
        while(temp<str.length())
        {
            values.push_back(str[temp]);
            temp++;
        }
        vector<string> cont;
        splitting(cont,values);
        mp[keys].push_back(cont);
    }
    string spell;cin>>spell;
    
    cout<<solve(spell,mp,dp)-1<<endl;//for(auto i:dp) cout<<i.first<<' '<<i.second<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}