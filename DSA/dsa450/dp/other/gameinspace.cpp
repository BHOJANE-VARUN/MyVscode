#include <bits/stdc++.h> 
using namespace std;
#include <bits/stdc++.h> 
int solve(int h,int a,int prev,vector<vector<int>> &dp)
{
    if(h<=0 || a<=0)
    {
        return 0;
    }

    if(dp[h][a]!=-1) return dp[h][a];

    int mars=INT_MIN,ven = INT_MIN,sat = INT_MIN;
    if(prev!=1)
     mars = 1 + solve(h+3,a+2,1,dp);
    if(prev!=2)
     ven = 1 + solve(h-4,a-8,2,dp);
    if(prev!=3)
     sat = 1 + solve(h-10,a+5,3,dp);

    return dp[h][a] = max(mars,max(ven,sat));
}
int gameSpace(int h, int a) {
    int time = 0;
    while(h > 0 && a > 0) {
        h += 3;
        a += 2;
        time++;
        
        if(h-4 > 0 && a-8 > 0) {
            h -= 4;
            a -= 8;
            time++;
        }
        else if(h-10 > 0) {
            h -= 10;
            a += 5;
            time++;
        }
        else{
            break;
        }
    }
    
    return time;
}
int gameSpace(int h, int a) {
  // Write your code here
  vector<vector<int>> dp(1000,vector<int> (1000,-1));
  return solve(h,a,0,dp)-1;

}
int main()
{
    cout<<gameSpace(5,8);
}