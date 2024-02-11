#include "algorithm"
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &a,int i,int j)
{
    
    if(i==a.size()-1) return 0;
    if(j==a.size()) return 100000;
    int test = __gcd(a[i],a[j]);
    while(j<a.size() && __gcd(a[i],a[j])==1)
    {
        j++;
    }
    if(j==a.size()) return 100000;
    int incl =1 + solve(a,j,j+1);
    int excl = solve(a, i,j+1);
    
    return min(incl,excl);
}
int minimumNumberOfMoves(int n, vector<int> &a) {
    // Write your code here.
    return solve(a,0,1);
}
int main()
{
    vector<int> test = {2,8,6,15};
    cout<<minimumNumberOfMoves(test.size(),test);
}