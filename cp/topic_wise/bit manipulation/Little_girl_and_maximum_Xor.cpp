#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{

{
    int l,r;
    int i = 63,j =63;
    cin>>l>>r;
    int ans =0;
    while(i>=0 and j>=0)
    {
        if(((((1ll<<i)&l)>0)==(((1ll<<j)&r)>0)))
        {
            i--,j--;
        }
        else{
           break; 
        }
    }
    //cout<<i<<endl;
    if(i==-1)
    {
        cout<<0<<endl;
        return 0;
    }
    ans = (ans | ((1ll<<i+1)-1));
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}