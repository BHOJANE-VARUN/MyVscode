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
    int n,a,b;
    cin>>n>>a>>b;
    if(a<b)
    {
        swap(a,b);
    }
    int ans =0;
    int f =0;
    for(int i =n-1;i>=0;i--)
    {

        if((((1<<i)&a)>0)==(((1<<i)&b)>0))
        {
            if(((1<<i)&a)==0)
            ans = (ans | (1<<i));
        }
        else{
            if(f==0)
            {
                f =1;
            }
            else{
                if(((1<<i)&b)==0)
                {
                    ans = (ans | (1<<i));
                }
            }
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}