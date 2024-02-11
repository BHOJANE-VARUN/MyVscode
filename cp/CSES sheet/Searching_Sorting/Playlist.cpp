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
    map<int,int> mp;
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int ans =1;
    int cur =0;
    for(int i =0,j =0;i<n;i++)
    {
        while(mp[arr[j]]<1 and j<n)
        {
            mp[arr[j]]++;
            j++;
        }
        ans = max(ans,j-i);
        mp[arr[i]]--;
    }
    cout<<ans;
}
//dusro ka code copy karne se khar nahi chalta bhai
}