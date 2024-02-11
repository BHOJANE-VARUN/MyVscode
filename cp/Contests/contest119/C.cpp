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
    int n,m;
    cin>>n>>m;
    int ans =INT_MAX;
    for(int i =0;i<n;i++)
    {
        int temp;
        cin>>temp;
        if(temp>=m)
        ans = min(ans,temp%m);
    }
    cout<<(ans==INT_MAX?-1:ans)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}