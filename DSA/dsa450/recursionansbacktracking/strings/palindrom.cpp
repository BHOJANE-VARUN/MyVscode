#include<iostream>
using namespace std;
bool palindrome(string &s,int low,int high)
{   if(high<low)return true;
    if(s[low]==s[high])
    {palindrome(s,++low,--high);}
    else{
        return false;
    }
}
int main()
{
    string s;
    cin>>s;
    cout<<palindrome(s,0,s.length()-1);
}