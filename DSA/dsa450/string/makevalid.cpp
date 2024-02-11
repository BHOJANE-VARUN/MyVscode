#include <bits/stdc++.h> 
using namespace std;
int findMinimumCost(string str) {
  stack<int> sk;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i]==123 || i==0)
    {
        sk.push(str[i]);
    }
    else 
    {   if(sk.empty()!=true)
        {if(sk.top()==123)
        {
            sk.pop();
        }
        else
        {
            sk.push(str[i]);
        }}
        else
        {
          sk.push(str[i]);
        }
        
        
    }
    
  }
  int size = sk.size();
  if(size%2!=0)
  {
    return -1;
  }
  int ans = 0;
  
  while(sk.empty()!=true)
  {
   char first = sk.top();
  sk.pop();
  char second = sk.top();
  sk.pop();
    if(first==second)
    {
      ans++;
    }
    else{
      ans+=2;
    }
  }
  return ans;
}
int main()
{
  string str = "}}}}}{";
  int ans = findMinimumCost(str);
  cout<<ans;
}
  
  
