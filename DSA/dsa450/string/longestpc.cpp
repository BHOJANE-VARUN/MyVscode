#include <bits/stdc++.h> 
using namespace std;
string longestPalinSubstring(string &str)
{  string temp;
   string ans;
   ans.push_back(str[0]);
   string s = str;
   reverse(str.begin(),str.end());
   for(int i =0;i<str.length();i++)
   {
       if(str[i]==s[i])
       {
           temp.push_back(str[i]);
       }
       else{
           if(temp.length()>ans.length())
           {
               ans = temp;
               temp = "";
           }
       }
   }
   if(temp.length()>ans.length())
    {
       return temp;        
    }
    return ans;
}
int main()
{   string s = "bbabcbcab";
    cout<<longestPalinSubstring(s);
}
