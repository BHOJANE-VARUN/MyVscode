#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
//4 8 5 3
//5 12 8 1
int solve(vector<pair<int,int>>&arr,int x,int i)
{
    if(i==arr.size()) return 0;
    int incl=0;
    if(x>=arr[i].first)
     incl = solve(arr,x-arr[i].first,i+1) + arr[i].second;
    int excl = solve(arr,x,i+1);
    return max(incl,excl);
}
int solveit(vector<pair<int,int>> &arr,int x)
{
    //include or exclude 
    //let at any point i have perform include/exclude means what will be the 
    //maximum pages i will get if i include it or if i exclude it
    //if i include then my x = x-arr[j].second 
    //if i exclude x is remain the same 
    //both cases my i will increment by one
    //base case if i==n then 0 therefore for all dp[i][n] = 0
    //visaulization of dp
    //at each value of x i.e from x=1 to x=x 
    //dp[i][j] will give me maximum pages can be purchased by i money
    // and at jth index(upto jth index in reverse order means
    // ki jth index paryant reverse order madhi gelo tar kiti maximum meleh)
    //dp[i][j] = max of dp[i-arr[j].first][j+1]+arr[j].second,dp[i][j+1]
    int n =arr.size();
  //  vector<vector<int>> dp(x+1,vector<int>(n+1,0));
    vector<int> cur(x+1,0),prev(x+1,0);
    for(int j = n-1;j>=0;j--)
    {
        for(int i =1;i<=x;i++)
        {
            int incl  =0;
            if(i>=arr[j].first)
                  incl = arr[j].second + prev[i-arr[j].first];
            int excl = prev[i];
            cur[i] = max(incl,excl);
        }
        prev = cur;
    }
    return cur[x];
}
signed main()
{   
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for(int i =0;i<n;i++)
    {
      cin>>arr[i].first;
    }
    for(int i =0;i<n;i++)
    {
      cin>>arr[i].second;
    }
   // int ans = solve(arr,x,0);cout<<ans<<endl;
   int ans = solveit(arr,x);cout<<ans<<endl;
//dusro ka code copy karne se ghar nahi chalta bhai
}