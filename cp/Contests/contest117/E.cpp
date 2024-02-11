#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 998244353
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
    int a,b;
    cin>>a>>b;
    int m,n;
    m = min(a,b);
    n = max(a,b);
    int ans = 0;
    if(n==m)
    {
        if(n%2==0)
        {
            int ele = n/2;
            ans = (2*((ele*(ele+1))%MOD)+((ele*ele)%MOD)+(((ele+1)*(ele+1))%MOD))%MOD;
        }
        else{
            ans = n+1;
        }
    }
    else{
        int count = (((m*(m+1)))%MOD)/2;
        if(n%2==0)
        {   
            ans += ((n/2)*count)%MOD;
            ans += (((n/2)+1)*count)%MOD;
        }
        else{
            ans = (((n+1)/2)*count)%MOD;
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}