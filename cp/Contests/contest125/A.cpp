#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{
test
{
    int n;cin>>n;
    string str;
    cin>>str;
    int ct =0;
    int ans = INT_MIN;
    int cur =0;
    for(int i =0;i<str.length();i++)
    {
        if(str[i]=='1')
        {
           ct++; 
           cur =0;
        } 
        else
        {
            cur++;
            ans = max(ans,cur);
        }
    }
    if(ans!=INT_MIN)
    cout<<ans+ct<<endl;
    else cout<<ct<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}