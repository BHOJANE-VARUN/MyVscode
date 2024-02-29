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
    int n;
    cin>>n;
    int temp = (n+1)/2;
   // cout<<temp<<endl;
    int ans = temp*(temp+1);
   // cout<<ans<<endl;
    if(n%2) ans -= temp;
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}