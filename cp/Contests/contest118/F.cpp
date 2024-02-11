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
    int x;
    cin>>x;
    int totalset = __builtin_popcount(x);
    if(totalset==1)
    {
        cout<<1<<endl;
        continue;
    }
    int one = 1;
    int second = -1;
    int index =0;
    for(int i =0;i<31;i++)
    {
        if((one<<i)&x)
        {   
            second =index;
            index =i; 
        }
    }

    int ele = second;
    ele -= (totalset-2);
    int ans = pow(2,ele);
    cout<<ans<<endl;
   
}
//dusro ka code copy karne se khar nahi chalta bhai
}