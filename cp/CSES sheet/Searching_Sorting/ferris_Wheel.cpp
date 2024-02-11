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
    int n,m;
    cin>>n>>m;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    int i =0,j=n-1;
    int ans =0;
    while(i<j)
    {
        if(arr[j]>m)
        {
            
            j--;
        }
        else if((arr[i]+arr[j])>m)
        {
            
            j--;
        }
        else{
            i++,j--;
        }
        ans++;
    }
    if(i==j) ans++;
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}