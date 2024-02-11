#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
signed main()
{
test
{
    int x,y,r;
    cin>>x>>y>>r;
    int extra = r/30;
    int ans = (extra+x)/y;
    cout<<((extra+x)%y==0?ans:ans+1)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}