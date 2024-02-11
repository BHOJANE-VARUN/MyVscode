#include <bits/stdc++.h>
using namespace std;

int isCyclicRotation(string &p, string &q) 
{   int len = p.length();
    for (int i = 0; i < len; i++)
    {
        for(int j =0;j<len-1-i;j++)
        {
            p.insert(p.end(),p[j]);
            

        }
        for (int j = len-1; j >=len-1-i; j--)
        {
            p.insert(p.end(),p[j]);
            
        }
       p.insert(p.end(),'V'); 
    }
    if(p.find(q)<p.length())
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
      
}
int main()
{
    string l = "asdf";
    string l1 = "fasd";
    int ans = isCyclicRotation(l,l1);
    cout<<ans;
}