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
    string str;cin>>str;

    int f =0;
    for(int i =1;i<str.length();i++)
    {
        if(str[i]==str[i-1])
        {
            cout<<1<<endl;
            f = 1;
            break;
        }
    }

    if(f==0) cout<<str.size()<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}