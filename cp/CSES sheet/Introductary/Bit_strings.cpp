#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int binaryexp(int base,int pow)
{
    if(pow==0) return 1;
    if(pow==1) return base;

    int ans = binaryexp(base,pow/2)%MOD;
    ans = (ans*ans)%MOD;
    if(pow%2) ans = (ans*base)%MOD;
    return ans;
}   
signed main()
{
    int n;
    cin>>n;
    cout<<binaryexp(2,n)<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}