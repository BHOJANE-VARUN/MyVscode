#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   
}
signed main()
{
test
{
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    int temp;
    int maxi = INT_MIN,mini = INT_MAX;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
       maxi = max(maxi,arr[i]);
       mini = min(mini,arr[i]);
    }
    if(maxi+mini>k and n!=1) cout<<N<<endl;
    else cout<<Y<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}