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
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans = INT_MIN;
    for(int i =0;i<n;i++)
    {
        int cur = arr[i]*(n-i);
        ans = max(ans,cur);
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}