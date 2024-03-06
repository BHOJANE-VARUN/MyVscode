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
    //10^5
    //10^5
    string str;
    cin>>str;
    int n = str.length();
    unordered_map<char,int> mp;
    for(auto i:str) mp[i]++;
    int ans =str.length();
    int ct =1;
    for(int i =0;i<n-1;i++)
    {
        if(str[i+1]==str[i])
        {
            ct++;
            ans = min(ans,mp[str[i]]-ct);
        }
        else{
            ct =1;
            ans = min(ans,mp[str[i]]-ct);
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}