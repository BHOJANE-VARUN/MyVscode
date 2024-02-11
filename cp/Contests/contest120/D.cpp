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
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    map<int,int> mp;
    for(int i =0;i<n;i++)
    {
        int sum =arr[i];
        for(int j =i;j<n;j++)
        {
            if(sum>n){
                break;
            }
            sum += arr[j];
            mp[sum]++;
        }
    }
    for(auto i:mp)
    {
        if(i.first)
        {
            cout<<i.second<<" ";
        }
    }
}
//dusro ka code copy karne se khar nahi chalta bhai
}