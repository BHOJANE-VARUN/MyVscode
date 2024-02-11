#include <bits/stdc++.h> 
using namespace std;
int ans;
void solve(vector<string> &words,int i,int m,vector<int> &freespace)
{
    if(words.size()==i)
    {   int temp =0;
        for(auto k:freespace)
        {   if(k==m)
        {
            continue;
        }
            temp += pow(k,3);
        }
        ans = min(ans,temp);
        return;
    }
    for(int j =0;j<freespace.size();j++)
    {   int temp;
            if(freespace[j]==m)
            temp = words[i].length();
            else temp = words[i].length()+1;
        if(freespace[j]>=temp)
        {   
            freespace[j] -= temp; 
            solve(words,i+1,m,freespace);
            freespace[j] += temp;
           
        }
    }
}

int wordWrap(vector<string> words,int m,int n)
{
    vector<int> freespac(n,m);
     ans = INT_MAX;
    solve(words,0,m,freespac);
    return ans;
}
// 4 5
// a
// bc
// def
// ghij
/*int calculateCost(int word, vector<int> &wordsLength, vector<int> &dp, int &m)
{
    int n = wordsLength.size();
    if (word == wordsLength.size())
    {
        return 0;
    }
    int &res = dp[word];
    if (res != -1)
    {
        return res;
    }

    int ans = INT_MAX;
    int current = 0;
    for (int w = word; w <= n - 1; w++)
    {
        if (current + wordsLength[w] <= m)
        {
            current += wordsLength[w] + 1;
            int cost = m - current + 1;
            int ans2 = cost * cost * cost + calculateCost(w + 1, wordsLength, dp, m);
            if (ans > ans2)
            {
                ans = ans2;
            }
        }
    }
    return res = ans;
}


int solvetab(vector<int>wordsLength,int m,int n)
{
    vector<int> dp(n+ 1,0);
    // int curr=0;
    // int prev=curr;
    for(int word=n-1;word>=0;word--)
    {
        int ans = INT_MAX;
        int current = 0;
        for (int w = word; w <= n - 1; w++)
        {
            if (current + wordsLength[w] <= m)
            {
                current += wordsLength[w] + 1;
                int cost = m - current + 1;
                int ans2 = cost * cost * cost + dp[w+1];
                if (ans > ans2)
                {
                    ans = ans2;
                }
            }
        }
        dp[word]=ans;
    }
    return dp[0];
}

int wordWrap(vector<string> words, int m, int n)
{
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<int>dp(n+1,-1);
    vector<int>wordsLength;
    for (int i = 0; i < n; i++)
    {
        wordsLength.push_back(words[i].size());
    }

    // int ans = calculateCost(0, wordsLength, dp, m);
    // return ans;

    return solvetab(wordsLength,m,n);
}*/
int main()
{
    vector<string> vec = {"a","bc","def","ghij"};
    cout<<wordWrap(vec,5,4);
}