#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> &num,int n,int k,int req,int sum)
{
    if(k==0)
    { 
        return true;
    }
    if(sum==req) return solve(num,num.size()-1,k-1,req,0);
    if(n==-1) return false;

    if(num[n]!=-1 && num[n]+sum<=req)
    {
        int i = num[n];
        num[n] =-1;
        if(solve(num,n-1,k,req,sum+i)) return true;
        num[n] = i;
        if(solve(num,n-1,k,req,sum)) return true;
    }
    else{
        if(solve(num,n-1,k,req,sum)) return true;
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int n, int k)
{
    // Write your code here.
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%k) return false;
    else solve(nums,n-1,k,sum/k,0);
}
int main()
{
    vector<int> vec = {5 ,1, 2, 6 ,7 ,1 ,2};
    cout<<canPartitionKSubsets(vec,vec.size(),4);
}