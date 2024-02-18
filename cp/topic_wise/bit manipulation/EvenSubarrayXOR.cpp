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
    vector<int> ans1(n),ans2(n);
    int i = 4;
    int fir =0,sec =0;
    while(fir<n and sec<n)
    {
        ans1[fir] = i;
        fir++;
        if(fir!=n)
        ans1[fir] = i+3;
        ans2[sec] = i+1;
        sec++;
        if(sec!=n)
        ans2[sec] = i+2;
        i += 4;
    }
    for(auto i:ans1) cout<<i<<" ";
    cout<<endl;
    for(auto i:ans2) cout<<i<<" ";
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}