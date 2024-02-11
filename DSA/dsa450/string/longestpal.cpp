#include <bits/stdc++.h>
#define lop(s,e) for(int i=s;i<e;i++)
#define whi(e) while(i<e)
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
          if((r-l)>ansp.second)
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
          if((r-l)>ansp.second)
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
int main()
{
    string str = longestPalinSubstring("abb");
    cout<<str;
    
}