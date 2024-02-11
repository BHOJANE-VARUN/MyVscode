#include<bits/stdc++.h>
using namespace std;
// void solve(vector<int>& nums1, vector<int>& nums2,int index,int &ans,int no)
// {
//     if(index==nums1.size())
//     {   int flag =1;
//         for(int i=1;i<nums1.size();i++)
//         {
//             if(nums1[i-1]>=nums1[i] || nums2[i-1]>=nums2[i])
//             {
//                 flag =0;
//                 break;
//             }
//         }
//         if(flag) ans = min(ans,no);
//         return;
//     }
//     int num = nums1[index],numd = nums1[index-1];
//     if(nums1[index]<=nums1[index-1] || nums2[index]<=nums2[index-1])
//     {swap(nums1[index-1],nums2[index-1]);int test = nums1[index],tte = nums2[index];
//     solve(nums1,nums2,index+1,ans,no+1);
//     swap(nums1[index-1],nums2[index-1]);};
//     solve(nums1,nums2,index+1,ans,no);
    
// }
// int minSwap(vector<int>& x, vector<int>& y) {
//     int ans = INT_MAX;
//     x.insert(x.begin(),-1);
//    y.insert(y.begin(),-1);
//     solve(x,y,1,ans,0);
//     return ans;
// }
int solve(vector<int> &x,vector<int> &y,int index,bool swapped)
{
    if(index==x.size()) return 0;

    int ans = INT_MAX;

    int prev1 = x[index-1];
    int prev2 = y[index-1];

    if(swapped) swap(prev1,prev2);

    if(x[index]>prev1 && y[index]>prev2)
    ans = solve(x,y,index+1,0);

    if(x[index]>prev2 && y[index]>prev1)
      ans = min(ans,1 + solve(x,y,index+1,1));

      return ans;
}
int solvemem(vector<int> &x,vector<int> &y,int index,bool swapped,vector<vector<int>>& dp)
{
    if(index==x.size()) return 0;

    if(dp[index][swapped]!=-1) return dp[index][swapped];

    int ans = INT_MAX;

    int prev1 = x[index-1]; 
    int prev2 = y[index-1];

    if(swapped) swap(prev1,prev2);

    if(x[index]>prev1 && y[index]>prev2)
    ans = solvemem(x,y,index+1,0,dp);

    if(x[index]>prev2 && y[index]>prev1)
      ans = min(ans,1 + solvemem(x,y,index+1,1,dp));

    dp[index][swapped] = ans;
    return ans;
}
int minSwap(vector<int>& x, vector<int>& y) {
    x.insert(x.begin(),-1);
   y.insert(y.begin(),-1);
   vector<vector<int>> dp(x.size()+1,vector<int> (x.size()+1,-1));
   bool swapi =0;
   return  solve(x,y,1,swapi,dp);
}
int main()
{
    vector<int> nums1 = {0,4,4,5,9}, nums2 = {0,1,6,8,10};
   
    cout<<minSwap(nums1,nums2);
}