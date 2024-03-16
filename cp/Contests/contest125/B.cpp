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
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    for(int i =0;i<str.length();i++)
    {
        if(str[i]=='0')
        {
            cout<<str[i];
        }
        else if(k>0)
        {
            cout<<'0';
            k--;
        }
        else{
            cout<<str[i];
        }
    }
    cout<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}