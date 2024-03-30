#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// dp[i] says that maximum sum that can be achieved by ending the subsequnce before ith element 
// NOTE : if arr[i]>arr[j] then only we can do anything else no
// we will traverse list backwards from i 
// if arr[i]>arr[j] then we can take then suppose if we take that element then dp[i] = dp[j]+1 ,1+ for ith element 
// else dp[i] remain same 
// ans : max(dp) 
int table(vector<int> &arr,int n)
{
    vector<int> dp(n+1,0);
    dp[0] = arr[0];
    for(int i =1;i<n;i++)
    {
        dp[i] = arr[i];
        for(int j =i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
            {
                dp[i] = max(dp[i],dp[j]+arr[i]);
            }
        }
    }
    return (*max_element(dp.begin(),dp.end()));
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    return table(rack,n);
}
signed main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<maxIncreasingDumbbellsSum(arr,n)<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}