#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
vector<string> ans;
void solve(int i,int j,string &s,unordered_map<string,bool> &mp,string cur)
{
    if(j==s.length() and i==s.length())
    {
        ans.push_back(cur);
        return;
    }
    if(j==s.length() or i==s.length())
        return;

    solve(i,j+1,s,mp,cur);
    string word = s.substr(i,j-i+1);
    if(mp.find(word)!=mp.end())
    {
        cur += (' ' + word);
        solve(j+1,j+1,s,mp,cur);
    }
    return;
}
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    unordered_map<string,bool> mp;
    for(auto i:dict)
        mp[i] = true;
    solve(0,0,s,mp,"");
    return ans;
}
signed main()
{

//dusro ka code copy karne se ghar nahi chalta bhai
}