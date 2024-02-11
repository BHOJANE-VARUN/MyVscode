#include <bits/stdc++.h> 
unordered_map<string,bool> mp; 
bool isScramble(string s, string r)
{
    // Write your code here.
    int n = s.size();
    if(s==r) return true;
    if(n==1) return false;

    string key = s + " " + r;
    if(mp.find(key)!=mp.end()) return mp[key];

    for(int i =1;i<n;i++)
    {
        if(isScramble(s.substr(0,i),r.substr(0,i)) && 
                isScramble(s.substr(i),r.substr(i)))
                return mp[key] = true;
        if(isScramble(s.substr(0,i), r.substr(n-i)) &&
                isScramble(s.substr(i), r.substr(0,n-i)))
            return mp[key] = true;
    
    }
    return mp[key] = false;
}