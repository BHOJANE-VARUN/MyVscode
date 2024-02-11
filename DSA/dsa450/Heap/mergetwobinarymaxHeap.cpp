#include <bits/stdc++.h> 
void heapify(int index,vector<int> &ans,int n)
{
    int large = index;
    int left = 2*large+1;
    int right = 2*large+2;

    if(left<n and ans[left]>ans[large])
    {
        large = left;
    }
    if(right<n and ans[right]>ans[large])
    {
        large = right;
    }
    if(large!=index)
    {
        swap(ans[large],ans[index]);
        heapify(large,ans,n);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans;
    ans.insert(ans.end(),arr1.begin(),arr1.end());
    ans.insert(ans.end(),arr2.begin(),arr2.end());
    for(int i =(ans.size()/2);i>=0;i--)
    {
        heapify(i,ans,ans.size());
    }
    return ans;
}