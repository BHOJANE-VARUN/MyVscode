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
    unordered_map<int,int> mp;
    for(int i =0;i<n;i++)
    {
        string num;
        cin>>num;
        int cur =0;
        for(auto j:num)
        {
            if(j=='1')
            {
                cur++;
            }
        }
        mp[cur]++;
    } 
    int ct =0;
    for(auto i:mp)
    {
        if(i.first==0)
        {
            continue;
        }
        ct++;
    }
    if(ct==1) cout<<"SQUARE"<<endl;
    else cout<<"TRIANGLE"<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}