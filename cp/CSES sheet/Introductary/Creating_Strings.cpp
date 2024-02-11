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
    set<string> ans;
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    ans.insert(str);
    while(next_permutation(str.begin(),str.end()))
    {
        ans.insert(str);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}