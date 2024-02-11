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
    int n,m;
    cin>>m>>n;
    int *arr = new int[n];
    int maxi =0;
    int mini = INT_MAX;
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      maxi = max(maxi,arr[i]);
      mini = min(mini,arr[i]);
    }
    cout<<m-((maxi-mini)*2)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}