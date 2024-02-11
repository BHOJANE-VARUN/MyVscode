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
    int n;
    cin>>n;
    int *arr = new int[n];
    int sum =0;
    for(int i =0;i<n;i++)
    {   
      cin>>arr[i];
      sum += arr[i];
    }
    sort(arr,arr+n);
    if(arr[0]!=1)
    {
        cout<<1<<endl;
        return 0;
    }
    int cur =0;
    for(int i =0;i<n;i++)
    {
        
        if(cur<(arr[i]-1))
        {
            cout<<(cur+1)<<endl;;
            return 0;
        }
        cur += arr[i];
    }
    cout<<sum+1<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}
// 1 2 3 4 