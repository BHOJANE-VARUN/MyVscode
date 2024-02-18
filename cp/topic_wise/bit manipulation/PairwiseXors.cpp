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
    if(n%2 || ((ceil(log2(n)) == floor(log2(n)))))
    {
        cout<<-1<<endl;
        continue;
    }
    int a =0,b =0,f =0;
    for(int i =0;i<31;i++)
    {
        if((1<<i)&n)
        {
            a = a|(1<<(i-1));
            if(f)
            b = b|(1<<(i-1));
            if(f==0) f=1;
        }
    }
    cout<<0<<" "<<a<<" "<<b<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}