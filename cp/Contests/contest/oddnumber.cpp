#include<bits/stdc++.h>
using namespace std;
bool factor(int n)
{   if(n<2)return n;
    int ans =1;
    for(int i =2;i<=n;i++)
    {  int count =0;
       while (n%i==0 && n!=0)
       {
        count++;
        n = n/i;
       }
        if(count>0)
        {
            ans = ans *(count+1);

        }
        if(n==0) break;
    }
    return ans%2;
}
vector<int> generate_subarray_multiplications(vector<int>& arr) {
    vector<int> subarray_multiplications;
    int n = arr.size();
    vector<int> dp(n, 1);  // DP array to store subarray multiplications

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = arr[i];
        for (int j = i + 1; j < n; ++j) {
            dp[j] = dp[j - 1] * arr[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            subarray_multiplications.push_back(dp[j] / (i > 0 ? dp[i - 1] : 1));
        }
    }

    return subarray_multiplications;
}
long long oddProducts(int n, vector<int> &a){
    // Write your code here.
    vector<int> re = generate_subarray_multiplications(a);
    int ans =0;
    for(auto i:re)
    { if(factor(i))
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {1,4};
    int n =2;
    cout<<oddProducts(n,vec);
}