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
    int f =1;
    int ans =0;
    int i =str.length()-1;
    while(i>=0)
    {
        if(str[i]=='0' and f==1)
        {
            f++;
            while(i>=0 and str[i]=='0')
            {
                i--;
            }
        }
        else if(str[i]=='0')
        {
            while(i>=0 and str[i]=='0')
            {
                i--;
            }
        }
        else{
            ans += f;
            while(i>=0 and str[i]=='1')
            {
                i--;
            }
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}