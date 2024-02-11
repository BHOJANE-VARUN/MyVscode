#include <bits/stdc++.h> 
using namespace std;
long long mod = 1e9+7;

long long int solvemem(int n,vector<long long> &dp)
{
  if(n==1)return 0;
  if(n==2)return 1;

  if(dp[n]!=-1)return dp[n];

   dp[n] =  ((n-1)*((solvemem(n-2,dp)+solvemem(n-1,dp))%mod))%mod;
  return dp[n];
}
long long int table(int n)
{
  vector<int> table(n+1,-1);
  table[0]=0;
  table[1]=0;
  table[2]=1;
  for(int i =3;i<n+1;i++)
  {
    table[i] = (i-1)*(table[i-2]%mod+table[i-1]%mod)%mod;
  }
  return table[n];
}
long long int countDerangement(int n) {
  // if(n==1)return 0;
  // if(n==2)return 1;


  // long long ans =  (((n-1)%mod)*((countDerangement(n-2)+countDerangement(n-1))%mod))%mod;
  // return ans;
  // vector<long long> dp(n+1,-1);
  // return solvemem(n, dp);
  return table(n);
}
int main()
{
    cout<<countDerangement(100);
}