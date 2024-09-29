#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
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
    int r =0;
    for(int i =0;i<n-1;i++) r += arr[i];
    int sum = r+arr[n-1];
    if(r<arr[n-1])
    {
        cout<<sum + (arr[n-1]-r)<<endl;
    }
    else cout<<sum<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}