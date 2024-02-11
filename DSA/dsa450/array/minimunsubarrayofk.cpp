#include <bits/stdc++.h> 
using namespace std;
int minsubarrSumToK(int n, int k, vector<int> &arr)
{
    int m =INT_MAX;
    
    
    for(int j =0;j<n;j++)
    {  int  sum =0;
        for (int i = j; i < n; i++)
        {
           sum += arr[i];
           if (sum>k)
           {
            m = min(m,i-j);
            break;
           }
           
        }
        

    }
    return m+1;
}
int main()
{
   vector<int> arr = {58, 60, 51, 60 ,13 ,77};
   int n = arr.size();
   int k = 61;
   int ans = minsubarrSumToK(n,k,arr);
    cout<<ans;
}