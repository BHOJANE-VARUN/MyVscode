#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int> &weight, vector<int> &value, int maxWeight,int index)
{   
    if(maxWeight==0) return 0;
    if(index==weight.size())
    {
        return 0;
    }
    if(0>maxWeight) return INT_MIN;
    


    //exclude
    int in = solve(weight,value,maxWeight,index+1);
    //include
    int temp = maxWeight-weight[index];
	int ex=0;
	if(temp>=0)
    ex = value[index] + solve(weight,value,temp,index+1);

    return max(in,ex);
}
int solvemem(vector<int> &weight, vector<int> &value, int maxWeight,int index,vector<vector<int>> &dp)
{   
    if(maxWeight==0) return 0;
    if(index==weight.size())
    {
        return 0;
    }
    
    if(dp[index][maxWeight]!=-1)return dp[index][maxWeight];

    //exclude
    int in = solvemem(weight,value,maxWeight,index+1,dp);
    //include
    int temp = maxWeight-weight[index];
	int ex=0;
	if(temp>=0)
    ex = value[index] + solvemem(weight,value,temp,index+1,dp);

    dp[index][maxWeight] =  max(in,ex);
    return dp[index][maxWeight];
}
int table(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
    for(int w = weight[0];w<=maxWeight;w++)
    {   if(weight[0]<=maxWeight)
        dp[0][w] = value[0];
        else dp[0][w] = 0;
    }

    for(int index =1;index<n;index++)
    {
        for(int w =0;w<=maxWeight;w++)
        {
        int in = dp[index-1][w];

        int temp = w-weight[index];
	    int ex=0;
	    if(temp>=0)
        ex = value[index] + dp[index-1][temp];

        dp[index][w] =  max(in,ex);
        }
    }
    return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    /*4
1 2 4 5
5 4 8 6
5*/
//return solve(weight,value,maxWeight,0);
// vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
// return solvemem(weight,value,maxWeight,0,dp);
return table(weight,value,n,maxWeight);

}
int main()
{
    vector<int> w = {1,2,4,5};
vector<int> v = {5,4,8,6};
cout<<knapsack(w,v,4,5);
}