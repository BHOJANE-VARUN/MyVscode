#include <bits/stdc++.h> 
using namespace std;
int upperbound(vector<int> &arr,int ele)
{
    int ans = -1;
    int low = 0,high = vec.size()-1;
    while (high -low>1)
    {   int mid = (high+low)/2;
        if(arr[mid]<=ele)low = mid+1;
        else high = mid;
    }
    if(arr[low]>ele)return low;
    if(arr[high]>ele)return high;
    return arr.size();
    
}
vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q)
{   vector<int> ans;
	sort(arr.begin(),arr.end());
    for(auto i:queries)
    {
        int index = upperbound(arr,i);
        for(int j = 0;j<index;j++)count+=arr[j];
        ans.push_back(count);
    }
    return ans;
}


