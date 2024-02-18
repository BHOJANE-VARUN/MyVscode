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
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int ct = n/k;
    if(ct%2)
    {
        int i =0;
        while(i<n-(n%k))
        {
            cout<<arr[i]<<" ";
            i++;
        }
        while(i<n)
        {
            cout<<(arr[i]^arr[n-(i%n)-1])<<" ";
        }
        cout<<endl;
    }else{
        int i =0;
        while(i<n-(n%k))
        {
            cout<<(arr[i]^arr[n-(i%n)-1])<<" ";
            i++;
        }
        while(i<n)
        {
            cout<<(arr[i])<<" ";
        }
        cout<<endl; 
    }
}
//dusro ka code copy karne se khar nahi chalta bhai
}