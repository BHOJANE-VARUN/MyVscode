#include <bits/stdc++.h> 
using namespace std;

bool checkStringExpression(string &str) {
	// Write your code here.
    stack<char> sk;
    for(int i =0;i<str.length();i++)
    {
        if(sk.empty() || str[i]!=')')
        {
            sk.push(str[i]);
        }
        else
        {   
            int count =0;
            char prev;
            while(sk.top()!='(')
            {
                prev = sk.top();
                count++;
                sk.pop();
            }
            if(count==1)
            {
                if(prev>47)
                {
                    return true;
                }
            }
            if(count==0)
            {
                return true;
            }
            sk.pop();
        }
    }
    return false;
}
int main()
{
    string str = "(((a+b)*(c+d)))";
    cout<<checkStringExpression(str);
}