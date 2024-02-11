//lower bound
//input (start index,end index,ele)
//output index of element equal to ele or just greater than ,if multiple present then first appearence is return && -1 if no element greater than
#include<iostream>
#include<vector>
using namespace std;
int lowerbound(vector<int> arr,int ele)
{
    int ans = -1;
    int low = 0,high = arr.size()-1;
    while (high>=low)
    {   int mid = (high+low)/2;
        if(arr[mid]>=ele)ans = mid,high = mid-1;
        else low = mid+1;
    }
    return ans;
    
}
int upperbound(vector<int> arr,int ele)
{
    int ans = -1;
    int low = 0,high = vec.size()-1;
    while (high>=low)
    {   int mid = (high+low)/2;
        if(arr[mid]>ele)ans = mid,high = mid-1;
        else low = mid+1;
    }
    return ans;
    
}
