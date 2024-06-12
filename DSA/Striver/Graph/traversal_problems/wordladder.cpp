#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// class Solution {
// public:
//     bool compare(string &a,string &b)
//     {
//         int f =0;
//         for(int i =0;i<a.size();i++)
//         {
//             if(a[i]!=b[i])
//                 f++;
//         }
//         if(f>1)
//             return false;
//         else return true;
//     }
//     int solve(string cur,vector<string>&word,vector<bool> &vis,string &endword,unordered_map<string,int>&mp)
//     {
//         if(cur==endword)
//             return 0;
//         if(mp[cur]!=0)
//             return mp[cur];
//         int ans = 1000000;
//         for(int i =0;i<word.size();i++)
//         {
//             if(!vis[i] and compare(word[i],cur))
//             {
//                 vis[i] = 1;
//                 ans = min(ans,1 + solve(word[i],word,vis,endword));
//                 vis[i] =0;
//             }
//         }
//         return mp[cur] = ans;
//     }
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         vector<bool> vis(wordList.size(),false);
//         unordered_map<string,int> mp;
//         int ans = 1 +  solve(beginWord,wordList,vis,endWord,mp);
//         return (ans==1000001?0:ans);
//     }
// };
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        queue<pair<string,int>> q;
        unordered_map<string,bool> mp;
        for(auto i:wordList)
        {
            mp[i] = false;
        }
        q.push({beginWord,0});
        mp[beginWord] = true;
        while (!q.empty())
        {
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            for(int i =0;i<n;i++)
            {
                string cur = str;
                for(char ch = 'a';ch<='z';ch++)
                {
                    cur[i] = ch;
                    if(cur==endWord)
                        return cnt+1;
                    if(mp.find(cur)!=mp.end() and mp[cur]==false)
                    {
                        mp[cur] = true;
                        q.push({cur,cnt+1});
                    }
                }
            }
        }
        return 0;
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}