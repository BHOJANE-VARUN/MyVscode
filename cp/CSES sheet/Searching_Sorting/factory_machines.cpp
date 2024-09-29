#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool mono(int arr[],int k,int n,int p)
{
    int ans =0;
    for(int i=0;i<n;i++)
    {
        ans += k/arr[i];
        if(ans>=p) return true;
    }
    return false;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    int ele = INT_MIN;
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
      ele = max(arr[i],ele);
    }
    int low =1,high = ele*k,mid;
    while(low<high)
    {
        mid = low + (high-low)/2;
        if(mono(arr,mid,n,k))
        {
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<high<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}