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
    map<int,int> mp;
    for(int i =0;i<22;i++)
    {
        int a,b;
        cin>>a>>b;
        int cur = a+(b*20);
        mp[cur]=i;
    }
   cout<<(*(--mp.end())).second+1<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}