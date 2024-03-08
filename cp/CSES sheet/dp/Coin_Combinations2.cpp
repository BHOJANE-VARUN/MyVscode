// #include<bits/stdc++.h>
// #define int long long int
// #define Y "YES"
// #define N "NO"
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// // int solve(vector<int> &arr,int n,int x,int index,vector<vector<int>> &dp)
// // {
// //     if(dp[x][index]!=-1)
// //     {
// //         return dp[x][index];
// //     }
// //     if(x==0) return 1;
// //     int ans =0;
// //     for(int i =index;i<n;i++)
// //     {
// //         if(x-arr[i]>=0)
// //         {
// //             ans =(ans +  solve(arr,n,x-arr[i],i,dp))%MOD;
// //         }
// //     }
// //     return dp[x][index] = ans;
// // }
// int solveit(int*arr,int n,int x)
// {
//   vector<vector<int>> dp(n + 1, vector<int>(x + 1));
//     // dp[i][k] = number of ways to construct sum k
//     // such that all coins before coin[i] are unusable
    
//     for(int i = 0; i < n; i++){
//         dp[i][0] = 1;
//     }
    
//     for(int i = n - 1; i >= 0; i--){
//         for(int sum = 1; sum <= x; sum++){
//             int skipping = dp[i + 1][sum];
//             int picking = 0;
//             if(arr[i] <= sum){
//                 picking = dp[i][sum - arr[i]];
//             }
//             dp[i][sum] = (skipping + picking) % MOD;
//         }
//     }
//     return dp[0][x];
// }
// signed main()
// {
//    int n,x;
//    cin>>n>>x;
//    int *arr = new int[n];
//    for(int i =0;i<n;i++)
//    {
//      cin>>arr[i];
//    }
//     // vector<vector<int>> dp(x+1,vector<int>(cur.size()+1,-1));
//     // int ans = solve(cur,cur.size(),x,0,dp);
//     int ans = solveit(arr,n,x);
//     cout<<ans<<endl;
// //dusro ka code copy karne se khar nahi chalta bhai
// }
/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    // dp[i][k] = number of ways to construct sum k
    // such that all coins before coin[i] are unusable
    
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int sum = 1; sum <= x; sum++){
            int skipping = dp[i + 1][sum];
            int picking = 0;
            if(a[i] <= sum){
                picking = dp[i][sum - a[i]];
            }
            dp[i][sum] = (skipping + picking) % MOD;
        }
    }
    cout << dp[0][x] << endl;
    return 0;
}