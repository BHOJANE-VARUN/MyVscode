#include <bits/stdc++.h> 
using namespace std;
string longestPalinSubstring(string str) {
    int len = str.length();
    string ans="";
    pair<int,int> ansp = {0,0};
    for (int i = 1; i <len; i++)
    {
        if(str[i-1]==str[i+1])
        {
          int l = i-1,r=i+1;
          while(l>=0 && r<len)
          {
            if (str[l]==str[r])
            {   
                l--,r++;
            }
            else
            {
                break;
            }
          }
          if((r-l)>ansp.second && l+1==0)
          {
            ansp.second = (r-l)-1;
            ansp.first = l+1;
          }  
        }
        if (str[i-1]==str[i])
        {
            int l = i-1,r = i;
            while(l>=0 && r<len)
          {
            if (str[l]==str[r])
            {   
                l--,r++;
            }
            else
            {
                break;
            }
          }
          if((r-l)>ansp.second && l+1 ==0)
          {
            ansp.second = (r-l)-1;
            ansp.first = l+1;
          }
        }
        
    }
    if(ansp.second==0)
    {
        ans.push_back(str[0]);
        return ans;
    }
   ans = str.substr(ansp.first,ansp.second);
    
    
 return ans;   
}
int minCharsforPalindrome(string str) {
	string strpal = longestPalinSubstring(str);
	return str.length()-strpal.length();
	
}
int main()
{
    string str = "aabaaac";
    int ans = minCharsforPalindrome(str);
    cout<<ans;
}