#include <bits/stdc++.h> 
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    int i =0;
    while(arr[i]<arr[i+1] && i<arr.size()){i++;}
    auto il = lower_bound(arr.begin(),(arr.begin()+i),k);
    auto ir = lower_bound(arr.begin()+i+1,arr.end(),k);
    if((*il)==k)return (il - arr.begin());
    if((*ir)==k)return (ir - arr.begin());
    return -1;
}
int main()
{
    vector<int> arr = {1,2,3,3};
    cout<<search(arr,arr.size(),4);
}
