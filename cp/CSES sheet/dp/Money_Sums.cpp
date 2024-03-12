#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
vector<bool> st(10000000,false);
int ct =0;
void solve(int i,int n,int *arr,int &sum)
{
    if(i==n)
    {
        if(sum!=0)
        {
            if(!st[sum]) ct++;
            st[sum]=true;
        }
       
        return;
    }
    sum += arr[i];
    solve(i+1,n,arr,sum);
    sum -= arr[i];
    solve(i+1,n,arr,sum);
}
void solveit(int *arr,int n)
{
    vector<vector<bool>> dp(n+1,vector<bool>(100001,0));
    for(int i =0;i<=n;i++) dp[i][0] = true;
    int sum =0;
    for(int i =1;i<=n;i++)
    {
        sum += arr[i-1];
        for(int j=1;j<=sum;j++)
        {
            bool incl = false;
            if(j-arr[i-1]>=0)
                incl = dp[i-1][j-arr[i-1]];
            bool excl = dp[i-1][j];
            dp[i][j] = (incl or excl);
        }
    }
    vector<int> ans;
    for(int i =1;i<=sum;i++)
    {
        if(dp[n][i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<" ";
}
signed main()
{
    // int n;
    // cin>>n;
    // int *arr = new int[n];
    // for(int i =0;i<n;i++)
    // {
    //   cin>>arr[i];
    // }
    // int ans =0;
    // solve(0,n,arr,ans);
    // cout<<ct<<endl;
    // for(int i =0;i<st.size();i++)
    //     if(st[i]) cout<<i<<" ";
    //bitset<1000001> bs;
  //  bs[0] = 1;
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      //bs |= bs<<arr[i];
    }
    // vector<int> ans;
    // for(int i =1;i<1000001;i++)
    // {
    //     if(bs[i]) ans.push_back(i);
    // }
    // cout<<ans.size()<<endl;
    // for(auto i:ans) cout<<i<<" ";
    solveit(arr,n);
//dusro ka code copy karne se ghar nahi chalta bhai
}