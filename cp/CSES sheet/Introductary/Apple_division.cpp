#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void solve(int &ans,int index,int left,int right,int n,int *arr)
{
    if(index==n)
    {
        ans = min(abs(left-right),ans);
        return;
    }

    solve(ans,index+1,left,right+arr[index],n,arr);
    solve(ans,index+1,left+arr[index],right,n,arr);
}
signed main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int ans = INT_MAX;
    solve(ans,0,0,0,n,arr);
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}