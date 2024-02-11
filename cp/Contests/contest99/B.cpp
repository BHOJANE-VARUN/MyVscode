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
    unordered_map<int,int> mp;
    int n;cin>>n;
    int *arr = new int[n];
    inputarrint(arr,n);
    int ans =INT_MIN;
    int ct =0;
    for(int i =0;i<n;i++)
    {
        if(mp[arr[i]]==0)
        {
            ct++;
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]]--;
            ct--;
        }
        ans = max(ans,ct);
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}