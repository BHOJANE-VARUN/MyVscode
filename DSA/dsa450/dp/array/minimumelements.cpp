// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int> &num, int index, int x) {
//     if (x == 0) {
//         return 0;
//     }
//     if (index >= num.size() || x < 0) {
//         return INT_MAX;
//     }

//     int includeCurrent = 1 + solve(num, index, x - num[index]);
//     int excludeCurrent = solve(num, index + 1, x);

//     return min(includeCurrent, excludeCurrent);
// }

// int minimumElements(vector<int> &num, int x) {
//     int result = solve(num, 0, x);
//     return (result == INT_MAX) ? -1 : result;
// }

// int main() {
//     vector<int> test = {1,2,3};
//     cout << minimumElements(test, 7);
// }
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int solve(vector<int>& nums, int k,vector<int> &dp) {
    if(k == 0) return 0;
    
    if(k < 0) return INT_MAX;

    if(dp[k]!=-1) return dp[k];
    int ans = INT_MAX;
    for(int i = 0; i < nums.size(); i++) {
        int temp = solve(nums, k - nums[i],dp);
        if(temp != INT_MAX) {
            ans = min(ans, temp + 1);
            dp[k] = ans;
        }
    }

    return ans;
}
//table[0]=0,table[1] = -1,1
int solvetab(int x,vector<int> &num)
{
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for (int  i = 0; i <= x; i++)
    {       
        for(int j =0;j<num.size();j++)
        { if(0<=(i-num[j]) && dp[i-num[j]]!=INT_MAX)
            dp[i] = min(dp[i],1 + dp[i-num[j]]);
        }
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    sort(num.rbegin(), num.rend());
    vector<int> dp(x+1, -1);
    int ans = solve(num, x,dp);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> test = {1, 2, 3};
    cout << solvetab(7,test);
}



