#include<iostream>
using namespace std;
void revstrrecu(string &s,int low,int high)
{   if(high<=low)return;
    swap(s[low],s[high]);
    revstrrecu(s,++low,--high);
}
int main()
{
    string s;
    cin>>s;
    revstrrecu(s,0,s.length()-1);
    cout<<s;
}