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
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
signed main()
{
test
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int m;
    cin>>m;
    int minus = 0,plus =0;
    for(int i =0;i<m;i++)
    {
        int temp;
        cin>>temp;
        if(temp>0) plus += temp;
        else minus += temp;
    }
    int first = plus,last = plus;
    int sum = first;
    int rsum = plus;
    for(int i=0;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        first = max(sum,first);
        rsum = max(arr[n-1-i],rsum+arr[n-1-i]);
        last = max(rsum,last);
    }
    cout<<max(first,last)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}