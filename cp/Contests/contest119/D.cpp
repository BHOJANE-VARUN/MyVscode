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
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    int cur =1;
    int ans = 0;
    for(int i =0;i<str.length()-1;i++)
    {
        if(str[i]==str[i+1]) cur++;
        else cur =1;
        ans = max(ans,cur);
    }
    char ch = str[str.length()-1];
    for(int i =0;i<q;i++)
    {
        char curch;
        cin>>curch;
        if(ch==curch) cur++;
        cout<<max(cur,ans)<<endl;
    }
}
//dusro ka code copy karne se khar nahi chalta bhai
}