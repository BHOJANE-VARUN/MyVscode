#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
// class Solution
// {
// public:
//     void dfs(vector<vector<string>> &ans,string cur,string &wordend,vector<string> &arr,unordered_map<string,vector<string>> &mp)
//     {
//         if(cur==wordend)
//         {
//             ans.push_back(arr);
//             return;
//         }

//         for(auto i:mp[cur])
//         {
//             arr.push_back(i);
//             dfs(ans,i,wordend,arr,mp);
//             arr.pop_back();
//         }
//     }
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
//     {
//         auto it = find(wordList.begin(),wordList.end(),endWord);
//         if(it==wordList.end())
//             return vector<vector<string>> ();
//         int n = beginWord.size();
//         vector<vector<string>> strans;
//         queue<pair<string, int>> q;
//         unordered_map<string, bool> mp;
//         unordered_map<string, vector<string>> ans;
//         int ansint = -1;
//         for (auto i : wordList)
//         {
//             mp[i] = false;
//         }
//         q.push({beginWord, 0});
//         mp[beginWord] = true;
//         while (!q.empty())
//         {
//             string str = q.front().first;
//             int cnt = q.front().second;
//             q.pop();
//             if (ansint != -1 and cnt > ansint)
//                 continue;
//             for (int i = 0; i < n; i++)
//             {
//                 string cur = str;
//                 int f = 0;
//                 for (char ch = 'a'; ch <= 'z'; ch++)
//                 {
//                     cur[i] = ch;
//                     if (cur == endWord)
//                     {
//                         if(ansint == -1)
//                         ansint = cnt + 1;
//                         ans[str].push_back(endWord);
//                         f = 1;
//                         break;
//                     }
//                     if (mp.find(cur) != mp.end() and mp[cur] == false)
//                     {
//                         mp[cur] = true;
//                         ans[str].push_back(cur);
//                         q.push({cur, cnt + 1});
//                     }
//                 }
//                 if (f)
//                     break;
//             }
//         }
//         for(auto I:ans)
//         {
//             cout<<I.first<<"== ";
//             for(auto J:I.second)
//                 cout<<J<<" ";
//             cout<<endl;
//         }
//         vector<string> varun;
//         varun.push_back(beginWord);
//         dfs(strans,beginWord,endWord,varun,ans);
//         return strans;
//     }
// };

void dfs(map<int, vector<vector<string>>> &ans, string &endword, vector<string> &wordlist, unordered_map<string, bool> &visit, vector<string> &cur, int cnt, int &intans)
{
    cout<<cur.back()<<endl;
    if (cnt > intans and intans != -1)
        return;
    if (cur.back() == endword)
    {
        if (intans == -1)
            intans = cur.size();
        ans[cur.size()].push_back(cur);
        return;
    }
    string str = cur.back();
    for (int i = 0; i < str.length(); i++)
    {
        string varun = str;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            varun[i] = ch;
            if (visit.find(varun) != visit.end() and visit[varun] == false)
            {
                cur.push_back(varun);
                visit[varun] = true;
                dfs(ans, endword, wordlist, visit, cur, cnt + 1, intans);
                cur.pop_back();
                visit[varun] = false;
            }
        }
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    auto it = find(wordList.begin(), wordList.end(), endWord);
    if (it == wordList.end())
        return vector<vector<string>>();
    int n = beginWord.size();
    unordered_map<string, bool> visit;
    map<int, vector<vector<string>>> q;
    unordered_map<string, bool> mp;
    unordered_map<string, vector<string>> ans;
    int ansint = -1;
    vector<string> cur;
    cur.push_back(beginWord);
    for (auto i : wordList)
        visit[i] = false;
    visit[beginWord] = true;
    dfs(q, endWord, wordList, visit, cur, 0, ansint);
    return (*q.begin()).second;
}

signed main()
{
    vector<string> wordlist = {"hot", "dog"};
    findLadders("hot", "dog", wordlist);
    return 0;
    // dusro ka code copy karne se ghar nahi chalta bhai
}