#include <bits/stdc++.h> 
using namespace std;
// int longestValidParentheses(string &str)
// {
//     // Write your code here.
//     stack<char> sk;
//     int temp =0;
//     int ans =0;
//     for(int i =0;i<str.length();i++)
//     {   if(sk.empty())
//         {
//             sk.push(str[i]);
//             if(temp!=0)
//             {
//                 temp=0;
//             }
//         }
//         else if(str[i]=='(')
//         {
//             sk.push(str[i]);
//         }
//         else{
//             if((!sk.empty()) && sk.top()=='(')
//             {
//                 sk.pop();
//                 temp += 2;
//                 ans = max(ans,temp);
//             }
//             else{
//                 sk.push(str[i]);
//                 temp=0;
//                 ans = max(ans,temp);
//             }
//         }
//     }
//     return ans;
// }
#include<bits/stdc++.h>
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans=max(ans,i-st.top());
        }
    }
    return ans;
}

int main()
{
    string str = "(()((((())))";
    cout<<longestValidParentheses(str);
}