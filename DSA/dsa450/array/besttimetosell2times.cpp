#include <bits/stdc++.h>
using namespace std; 
int maxProfit(vector<int>& arr, int n)
{
    vector<int> ans(n,0);
    int size = ans.size();
    int maxl = 0,maxr =0;
    int low = arr[0],high = arr[n-1];
    int curl =0, curr=0;
    for(int i =0;i<n;i++)
    {
         curl = arr[i]-low;
        maxl = max(maxl,curl);
        if(curl<=0)
        {
            low = arr[i];
        }
        curr = high-arr[n-1-i];
        maxr = max(maxr,curr);
        if(curr<=0)
        {
            high = arr[n-1-i];
        }
        ans[i]+=maxl;
        ans[size-1-i]+=maxr;
        
    }
    return *(max_element(ans.begin(),ans.end()));
}
int main()
{
    vector<int> arr = {3 ,3, 5 ,0 ,3 ,1 ,4};
    int n = arr.size();
    int ans = maxProfit(arr,n);
    cout<<ans;
}