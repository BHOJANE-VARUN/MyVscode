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
test
{
    int n,m;cin>>n>>m;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int x;cin>>x;
    int f =1;
    for(int i =0;i<n-1;i++)
    {
        if(x/2<arr[i])
        {
            arr[i] = x-arr[i];
        }
        if(arr[i+1]<arr[i])
        {
            cout<<"NO"<<endl;
            f =0;
            break;
        }
    }
    if(f) yes;
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}