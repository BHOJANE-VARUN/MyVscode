#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
//dp[i][prev]
// this means that we have end the subsequnce before or on ith element with prev element 
int solveit(int n,int arr[])
{
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i =1;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return (*max_element(dp.begin(),dp.end()));
}
signed main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<solveit(n,arr)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}