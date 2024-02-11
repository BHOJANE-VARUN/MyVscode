#include <bits/stdc++.h> 
using namespace std;
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{   int first=-1,last=-1;
    int low =0,high = n-1;
    while(low<=high)
    {   int mid = low+(high-low)/2;
        if(arr[mid]==k)first = mid,high = mid-1;
        else if (arr[mid]>k)high = mid-1;
        else low = mid+1;
    }
    low =0,high =n-1;
    while(low<=high)
    {   int mid = low+(high-low)/2;
        if(arr[mid]==k)last = mid,low = mid+1;
        else if (arr[mid]>k)high = mid-1;
        else low = mid+1;
    }              
    return {first,last};
}
int main()
{
    vector<int> arr = {1,2,2,4,5};
    pair<int,int> test = firstAndLastPosition(arr,arr.size(),1);
    cout<<test.first<<"  "<<test.second;
}