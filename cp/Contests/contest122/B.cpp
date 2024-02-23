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
test
{
    int n,m,x,y,l;
    cin>>n>>m>>x>>y>>l;
    if(l>max(n,m))
    {
        cout<<1<<endl;
        continue;
    }
    if(l==1)
    {
        cout<<(n*m)<<endl;
        continue;
    }
    int ans =0;
    ans += x/l;
    ans += y/l;
    ans += (n-x)/l;
    ans += (m-y)/l;
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}