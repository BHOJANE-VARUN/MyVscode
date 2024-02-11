#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void solve(int i,int cur,int helper,int tar)
{
    if(i==2)
    {
        cout<<cur<<" "<<helper<<endl;
        cout<<cur<<" "<<tar<<endl;
        cout<<helper<<" "<<tar<<endl;
        return;
    }
    solve(i-1,cur,tar,helper);
    cout<<cur<<" "<<tar<<endl;
    solve(i-1,helper,cur,tar);
}
signed main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<" "<<3<<endl;
        return 0;
    }
    cout<<pow(2,n)-1<<endl;
    solve(n,1,2,3);
//dusro ka code copy karne se khar nahi chalta bhai
}