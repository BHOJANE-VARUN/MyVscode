#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int> &arr,int n,int i,int j)
{
    if(i==j)
    {
        return arr[i];
    }
    
    int nonmer +=arr[i]+ accumulate(arr.begin()+i,j-arr.end()) + solve(arr,n,i,i) + solve(arr,n,i+1,j);
    int mer =arr[i+1] + arr[i] + accumulate(arr.begin()+i+1,j-arr.end()) + solve(arr,n,i+2,j);
    return min(nonmer,mer);
}
int findMinCost(vector<int> &arr, int n){
    // Write your code here.
    //5 2
//7 1 6 9 2
return solve(arr,n,0);
}
int main()
{
    vector<int> test = {1,3,7};
    cout<<findMinCost(test,test.size());
}