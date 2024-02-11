#include <bits/stdc++.h>
using namespace std; 
int threeSumSmaller(int n, vector<int> arr, int target) {
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum = target-arr[i];
        int low =i+1,high =n-1;
        while(high>low)
        {
            if(arr[low]+arr[high]>=sum)high--;
            else ans+=high-low,low++;
        }
    }
    return ans;
}
