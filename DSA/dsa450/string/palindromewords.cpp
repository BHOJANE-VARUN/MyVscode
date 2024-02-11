#include <bits/stdc++.h>
using namespace std;
bool chechpalin(string str)
{	
    int i =0,high = str.length()-1;
    while(high>i)
    {
        if(tolower(str[i])==tolower(str[high]))
        {
            i++,high--;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}
int countNumberOfPalindromeWords(string s)
{   if(s.length()<2)
	{
		return s.length();
	}
	int count =0;
    int start = 0;
	for(int i=1;i<s.length();i++)
    {
        if((s[i]==32 && s[i-1]!=32) )
        {
            string temp = s.substr(start,i-start);
            if(chechpalin(temp)==true)
            {
                count++;
            }
            
        }
        else if(s[i]!=32 && s[i-1]==32)
        {
            start=i;
        }
        if( i==s.length()-1)
        {
            string temp = s.substr(start,i-start+1);
            if(chechpalin(temp)==true)
            {
                count++;
            }

        }
    }
	return count;
}
int main()
{
    string str = "a w e r t y u";
    int test = countNumberOfPalindromeWords(str);
    cout<<test;
}