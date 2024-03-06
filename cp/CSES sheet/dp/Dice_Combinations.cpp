#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;

int solve(int ct,map<int,int> &mp)
{
    if(mp[ct]!=0)
    {
        return mp[ct];
    }
    if(ct==0)
    {
        return 1;
    }
    if(ct<0)
    {
        return -1;
    }
    int cur =0;
    for(int i =1;i<7;i++)
    {
        int state = solve(ct-i,mp);
        if(state!=-1)
        {
            cur+=state;
        }
        cur = cur%MOD;
    }
    return mp[ct]=cur;
}
int solvemem(int ct)
{
    vector<int> dp(ct+1,0);
    dp[0] = 1;
    for(int i=1;i<=ct;i++)
    {
        for(int j =1;j<7;j++)
        {
            if(i-j>=0)
            {
                dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }
    }
    return dp[ct];
}
//1=1
//2= 1 1, 2
//3 = 1 1 1,1 2,2 1,3
signed main()
{
    int n;
    cin>>n;
    // map<int,int> mp;
    // int ans = solve(n,mp)%MOD;
    int ans = solvemem(n);
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}