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
    
    int mini1=INT_MAX,mini2=INT_MAX;
    int sum =0;
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      sum += arr[i];
    }
    sort(arr,arr+n);
    if(n==2)
    {
        cout<<sum<<endl;
        continue;
    }
    cout<<(sum*2)-arr[0]-arr[1]<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}