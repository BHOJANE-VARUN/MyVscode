#include <bits/stdc++.h>
using namespace std;
// top down approch with dp 1d array
int solve(int index,vector<int> &nums,vector<int> &dp)
{   //base case
    if(index>=nums.size()) return 0;

    //dp test case
    if(dp[index]!=INT_MAX)
    {
        return dp[index];
    }

    //exclude
    int ex = solve(index+1,nums,dp);
    //include
    int in = nums[index]+solve(index+2,nums,dp);
    dp[index]=max(in,ex);
    return dp[index];
}

//shorter code with ans,output variable replaced by return type int(recursive) 
#include <bits/stdc++.h>
int solve(int index,vector<int> &nums)
{   //base case
    if(index>=nums.size()) return 0 ;

    //exclude
    int ex =solve(index+1,nums);
    //include
    int in = nums[index]+solve(index+2,nums);
    return max(ex,in);
}
//bottom to top by table
int dptable(vector<int> &nums)
{
    vector<int> table(nums.size(),0);
    table[0] = nums[0],table[1]=max(nums[0],nums[1]);
    for(int i =2;i<nums.size();i++)
    {   
        table[i] = max(table[i-1],nums[i]+table[i-2]);
    }
    //return max(table[nums.size()-1],table[nums.size()-2]);
    return table[nums.size()-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,INT_MAX);
    int ans =0;
    ans = solve(0,nums,dp);
    return ans;
}
//if same question is given in which the elements in arrage in circular manner then
// the first and last element will be adjcent,therefore to get answer calculate one part of in 
//which first element is absent and in one part last element is absent,and return the max of both of them
int main()
{
    vector<int> test = {76 ,31 ,35, 96, 7, 20, 22, 6 ,92, 76};
    //int ans = maximumNonAdjacentSum(test);
    int ans = dptable(test);
    cout<<ans;
}