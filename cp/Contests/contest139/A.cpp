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
    int n,c;cin>>n>>c;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<int> cnt(n,0);
    for(int i =0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            int cur = arr[i]*arr[j];
            cnt[i] += cur;
            cnt[j] += cur;
        }
    }
    sort(cnt.begin(),cnt.end());
    int ans =0;
    int varun =0;
    for(int i =0;i<n;i++)
    {
        int cur = varun*cnt[i];
        if(cnt[i]-cur<c)
        {
            ans++;
            varun += cnt[i];
            c = c - cnt[i]+cur;
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}