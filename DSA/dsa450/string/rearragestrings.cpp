#include <bits/stdc++.h> 
using namespace std;
string a,b,c;
bool check(int i,int j,int k)
{   if(i==a.length() && j==b.length() && k==c.length())return true;
    if(a[i]==c[k] && b[j]==c[k])
    {
        return check(++i,j,++k) || check(i,++j,++k);
    }
    else if(a[i]==c[k])
    {
        return check(++i,j,++k);
    }
    else if(b[j]==c[k])
    {
        return check(i,++j,++k);
    }
    else
    {
        return false;
    }
    
}
bool isInterleave(string aa, string ba, string ca){
    a = aa;
    b = ba;
    c = ca;
	return check(0,0,0);
}
int main()
{ //abcbbc bcabc abcbcabbcbc
    string s1 = "abcbbc";
    string s2 = "bcabc";
    string s3 = "abcbcabbcbc";
    cout<<isInterleave(s1,s2,s3);
}