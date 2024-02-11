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

{
    int n,m,k;
    cin>>n>>m>>k;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int *arr2 = new int[n];
    for(int i =0;i<m;i++)
    {
      cin>>arr2[i];
    }
    sort(arr,arr+n);
    sort(arr2,arr2+m);
    int i =0;
    int j =0;
    int ans =0; 
    while(i<n and j<m)
    {
        if(abs(arr2[j]-arr[i])<=k)
        {
            i++,j++;
            ans++;
        }
        else{
            if(arr[i]<arr2[j]) i++;
            else j++;
        }
    }
    cout<<ans<<endl; 
}
//dusro ka code copy karne se khar nahi chalta bhai
}