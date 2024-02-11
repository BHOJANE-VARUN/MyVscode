#include <bits/stdc++.h>
using namespace std; 
int minShift(string &s1, string &s2)
{   int l1 = s1.length(),l2 = s2.length();
    string str1 = s1;
    string str2 = s2;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1!=str2)return -1;   
    int i1=l1-1;
    int i2=l2-1;
    int ans =0;
    while(i1>=0 && i2>=0)
    {
        if(s1[i1]==s2[i2])i1--,i2--;
        else ans++,i2--;
    }
    return ans;
}