// #include<bits/stdc++.h>
// #define int long long int
// #define Y "YES"
// #define N "NO"
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// bool monotonic(int cur,int* arr)
// {
    
// }
// signed main()
// {
//     int n;
//     cin>>n;
//     int *arr = new int[n];
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     for(int i =0;i<n;i++)
//     {
//       cin>>arr[i];
//       mini = min(mini,arr[i]);
//       maxi = max(maxi,arr[i]);
//     }
//     int mid;
//     while(mini<maxi)
//     {
//       mid = (maxi+mini)/2;
//       if(mid)
//     }
// //dusro ka code copy karne se khar nahi chalta bhai
// }
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
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    int mid = (n)/2;
    int ans =0;
    for(int i =0;i<n;i++)
    {
        ans += abs(arr[i]-arr[mid]);
    }
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}