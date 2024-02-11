// #include <bits/stdc++.h> 
// using namespace std;
// int solve(vector<int>&arr,int n,int index)
// {
//     if(n==1) return 0;
//     if(index==n)return 1000;
//     if(arr[index]==INT_MAX) return solve(arr,n,index+1);

//     int ans = INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         if(i==index)
//         {
//             ans = min(ans,solve(arr,n,index+1));
//         }
//         else{
//             if(arr[i]==INT_MAX)continue;
//             int temp = arr[i] + arr[index];
//             arr[i] += arr[index],arr[index] =INT_MAX;
//             ans = min(ans,temp+solve(arr,n-1,index+1));
//             arr[index] = temp-arr[i];
//             arr[i] -=arr[index];
//         }

//     }
//     return ans;
// }
// int findMinCost(vector<int> &arr, int n){
//     return solve(arr,n,0);
// }
// int main()
// {
//     vector<int> arr = {1,3,7};
//     cout<<findMinCost(arr,3);
// }
#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& arr, int n, int index) {
    if (n == 1) return 0;
    if (index == n) return INT_MAX;
    if (arr[index] == INT_MAX) return solve(arr, n, index + 1);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i == index) {
            ans = min(ans, solve(arr, n, index + 1));
        } else {
            if (arr[i] == INT_MAX) continue;
            int temp = arr[i] + arr[index];
            arr[i] += arr[index];
            arr[index] = INT_MAX;
            int t = solve(arr,n-1,index+1);
            if(t!=INT_MAX)ans = min(ans, temp + t);
            arr[index] = temp - arr[i];
            arr[i] -= arr[index];
        }
    }
    return ans;
}

int findMinCost(vector<int>& arr, int n) {
    return solve(arr, n, 0);
}

int main() {
    vector<int> arr = {1, 3, 7};
    cout << findMinCost(arr, 3);
}
