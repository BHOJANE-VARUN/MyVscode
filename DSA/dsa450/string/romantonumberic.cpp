#include <bits/stdc++.h>
using namespace std;
int value(char &ch)
{
    switch(ch)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;

    }
}

int romanToInt(string s) {
    int  ans =0;
    int i =0;
    while(i<s.length())
    {
        if(value(s[i+1])>value(s[i]))
        {
            ans += value(s[i+1])-value(s[i]);
            i+=2;
        }
        else{
            ans+= value(s[i]);
            i++;
        }

    }
    

    return ans;
}