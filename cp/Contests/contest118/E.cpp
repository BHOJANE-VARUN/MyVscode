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
    int temp =1;
    int one = 1;
    int index =0;
    for(int i =0;i<31;i++)
    {
        if((one<<i)&x)
        {   temp =1;
            temp = temp<<i;
            index =i;
        }
    }
    int allset = (1 << index) - 1;
    int first = (allset & x);
   // cout<<index<<endl;
   // cout<<x<<endl;
    cout<<temp<<" "<<first<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}