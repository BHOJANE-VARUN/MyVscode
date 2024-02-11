#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<int> sk;
    for(int i =0;i<s.length();i++)
    {
        if(sk.empty())
        {
            sk.push(s[i]);
        }
        else if(s[i]!=')')
        {
            sk.push(s[i]);
        }
        else{
            int t = sk.top(),ele = s[i];
            if(t=='(' && ele==')')
            {
                return true;
            }
            else{
                int count=0;
                char prev=sk.top();
                while(sk.top()!='(' && (!sk.empty()))
                {
                    prev = sk.top();
                    sk.pop();
                    count++;
                }
                if(count==1 && (47<prev))
                {
                    return true;
                }
                sk.pop();
            }
        }
    }
    return false;
}
