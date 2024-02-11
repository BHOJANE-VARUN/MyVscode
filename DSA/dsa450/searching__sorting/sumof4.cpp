#include <bits/stdc++.h>
using namespace std;
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i =0;i<arr.size()-3;i++)
    {
        for(int j=i+1;j<arr.size()-2;j++)
        {
            int sum = target-arr[i]-arr[j];
            int low = j+1,high = n-1;
            while(low<high)
            {
                if(arr[low]+arr[high]==sum)return "Yes";
                else if(arr[low]+arr[high]>sum)high--;
                else low++;
            }
        }
    }
    return "No";
}

