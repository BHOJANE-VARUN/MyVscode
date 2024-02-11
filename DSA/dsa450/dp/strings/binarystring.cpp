#include <bits/stdc++.h> 
using namespace std;
int solve(string &s,int j,int i,char ch)
{
    if(i==s.length()) return 0;

    int incl =INT_MAX;
    if(s[j]=='0' && s[j]==s[i])
    {   int exl;
        if(ch=='0')  exl = solve(s,j+1,i+1,ch);
        else  exl = 2 + solve(s,j+2,i+2,'1');
        return exl;
    }
    
    if(s[j]=='0' && s[i]=='1')
    {   int incl;
        if(ch=='0')
        {
            incl = solve(s,j+2,i+2,'1');
        }
        else {
            return 1000;
        }
        return incl;
    }
}
int minimumNumberOfOperation(int n, string &s) {
    // Write your code here.
}